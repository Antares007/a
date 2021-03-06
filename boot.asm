; Assemble boot sector and insert it into a 1.44MiB floppy image
;
; nasm -f bin boot.asm -o boot.bin
; dd if=/dev/zero of=disk.img bs=512 count=2880
; dd if=boot.bin of=disk.img bs=512 conv=notrunc

BITS 16
; Bootloader starts at segment:offset 07c0h:0000h
section bootloader, vstart=0000h
  jmp 7c0h:__START__

__START__:
  mov ax, cs
  mov ds, ax
  mov es, ax
  mov ss, ax
  xor sp, sp
  cld
  ;Clear screen
  mov ax, 03h
  int 10h
  ;Set limit of 4GiB and base 0 for FS and GS
  call 7c0h:unrealmode
  ;Enable the APIC
  call enable_lapic
  ;Move the payload to the expected address
  mov si, payload_start_abs
  mov cx, payload_end-payload + 1
  mov di, 400h              ;7c0h:400h = 8000h
  rep movsb
  ;Wakeup the other APs
  call lapic_send_init      ;INIT
  mov cx, WAIT_10_ms
  call us_wait
  call lapic_send_sipi      ;SIPI
  mov cx, WAIT_200_us
  call us_wait
  call lapic_send_sipi      ;SIPI
  jmp 0000h:8000h           ;Jump to the payload

us_wait:                    ;CX = Wait (in ms) Max 65536 us (=0 on input)
  mov dx, 80h               ;POST Diagnose port, 1us per IO
  xor si, si
  rep outsb
  ret

WAIT_10_ms     EQU 10000
WAIT_200_us    EQU 200

enable_lapic:
  ;Enable the APIC globally
  ;On P6 CPU once this flag is set to 0, it cannot be set back to 16
  ;Without an HARD RESET
  mov ecx, IA32_APIC_BASE_MSR
  rdmsr
  or ah, 08h        ;bit11: APIC GLOBAL Enable/Disable
  wrmsr
  ;Mask off lower 12 bits to get the APIC base address
  and ah, 0f0h
  mov DWORD [APIC_BASE], eax
  ;Newer processors enables the APIC through the Spurious Interrupt Vector register
  mov ecx, DWORD [fs: eax + APIC_REG_SIV]
  or ch, 01h                                ;bit8: APIC SOFTWARE enable/disable
  mov DWORD [fs: eax+APIC_REG_SIV], ecx
  ret

lapic_send_sipi:
  mov eax, DWORD [APIC_BASE]
  ;Destination field is set to 0 has we will use a shorthand
  xor ebx, ebx
  mov DWORD [fs: eax+APIC_REG_ICR_HIGH], ebx
  ;Vector: 08h (Will make the CPU execute instruction ad address 08000h)
  ;Delivery mode: Startup
  ;Destination mode: ignored (0)
  ;Level: ignored (1)
  ;Trigger mode: ignored (0)
  ;Shorthand: All excluding self (3)
  mov ebx, 0c4608h
  mov DWORD [fs: eax+APIC_REG_ICR_LOW], ebx  ;Writing the low DWORD sent the IPI
  ret

lapic_send_init:
  mov eax, DWORD [APIC_BASE]
  ;Destination field is set to 0 has we will use a shorthand
  xor ebx, ebx
  mov DWORD [fs: eax+APIC_REG_ICR_HIGH], ebx
  ;Vector: 00h
  ;Delivery mode: Startup
  ;Destination mode: ignored (0)
  ;Level: ignored (1)
  ;Trigger mode: ignored (0)
  ;Shorthand: All excluding self (3)
  mov ebx, 0c4500h
  mov DWORD [fs: eax+APIC_REG_ICR_LOW], ebx  ;Writing the low DWORD sent the IPI
  ret

IA32_APIC_BASE_MSR  EQU 1bh
APIC_REG_SIV        EQU 0f0h
APIC_REG_ICR_LOW    EQU 300h
APIC_REG_ICR_HIGH   EQU 310h
APIC_REG_ID         EQU 20h
APIC_BASE            dd 00h

unrealmode:
  lgdt [cs:GDT]
  cli
  mov eax, cr0
  or ax, 01h
  mov cr0, eax
  mov bx, 08h
  mov fs, bx
  mov gs, bx
  and ax, 0fffeh
  mov cr0, eax
  sti
  ;IMPORTAT: This call is FAR!
  ;So it can be called from everywhere
  retf

GDT:
  dw 0fh
  dd GDT + 7c00h
  dw 00h
  dd 0000ffffh
  dd 00cf9200h

payload_start_abs:            ; payload starts at segment:offset 0800h:0000h
section payload, vstart=0000h, align=1
payload:
  ;IMPORTANT NOTE: Here we are in a \"new\" CPU every state we set before is no
  ;more present here (except for the BSP, but we handler every processor with
  ;the same code).
  jmp 800h: __RESTART__

__RESTART__:
  mov ax, cs
  mov ds, ax
  xor sp, sp
  cld
  ;IMPORTANT: We can't use the stack yet. Every CPU is pointing to the same stack!
  ;Get an unique id
  mov ax, WORD [counter]
  .try:
    mov bx, ax
    inc bx
    lock cmpxchg WORD [counter], bx
  jnz .try
  mov cx, ax            ;Save this unique id
  ;Stack segment = CS + unique id * 1000
  shl ax, 12
  mov bx, cs
  add ax, bx
  mov ss, ax
  ;Text buffer
  push 0b800h
  pop es
  ;Set unreal mode again
  call 7c0h:unrealmode
  ;Use GS for old variables
  mov ax, 7c0h
  mov gs, ax
  ;Calculate text row
  mov ax, cx
  mov bx, 160d           ;80 * 2
  mul bx
  mov di, ax
  ;Get LAPIC id
  mov ebx, DWORD [gs:APIC_BASE]
  mov edx, DWORD [fs:ebx + APIC_REG_ID]
  shr edx, 24d
  call itoa8
  cli
  hlt
  ;DL = Number
  ;DI = ptr to text buffer

itoa8:
  mov bx, dx
  shr bx, 0fh
  mov al, BYTE [bx +  digits]
  mov ah, 09h
  stosw

  mov bx, dx
  and bx, 0fh
  mov al, BYTE [bx +  digits]
  mov ah, 09h
  stosw
  ret

digits  db "0123456789abcdef"
counter dw 0

payload_end:

; Boot signature is at physical offset 01feh of
; the boot sector
section bootsig, start=01feh
 dw 0aa55h
