#Calling Conventions for 64-bit C Code
#The 64-bit calling conventions are a bit more detailed, and they are explained fully in the AMD64 ABI Reference. You can also get info on them at Wikipedia. The most important points are (again, for 64-bit Linux, not Windows):
#
#From left to right, pass as many parameters as will fit in registers. The order in which registers are allocated, are:
#For integers and pointers, rdi, rsi, rdx, rcx, r8, r9.
#For floating-point (float, double), xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7
#Additional parameters are pushed on the stack, right to left, and are removed by the caller after the call.
#After the parameters are pushed, the call instruction is made, so when the called function gets control, the return address is at (%rsp), the first memory parameter is at 8(%rsp), etc.
#THE STACK POINTER %RSP MUST BE ALIGNED TO A 16-BYTE BOUNDARY BEFORE MAKING A CALL. Fine, but the process of making a call pushes the return address (8 bytes) on the stack, so when a function gets control, %rsp is not aligned. You have to make that extra space yourself, by pushing something or subtracting 8 from %rsp.
#The only registers that the called function is required to preserve (the calle-save registers) are: rbp, rbx, r12, r13, r14, r15. All others are free to be changed by the called function.
#The callee is also supposed to save the control bits of the XMCSR and the x87 control word, but x87 instructions are rare in 64-bit code so you probably don't have to worry about this.
#Integers are returned in rax or rdx:rax, and floating point values are returned in xmm0 or xmm1:xmm0.
#This program prints the first few fibonacci numbers, illustrating how registers have to be saved and restored:
#
#fib.s
# -----------------------------------------------------------------------------
# A 64-bit Linux application that writes the first 90 Fibonacci numbers.  It
# needs to be linked with a C library.
#
# Assemble and Link:
#     gcc fib.s
# -----------------------------------------------------------------------------

        .global main

        .text
main:
        push    %rbx                    # we have to save this since we use it

        mov     $90, %ecx               # ecx will countdown to 0
        xor     %rax, %rax              # rax will hold the current number
        xor     %rbx, %rbx              # rbx will hold the next number
        inc     %rbx                    # rbx is originally 1
print:
        # We need to call printf, but we are using eax, ebx, and ecx.  printf
        # may destroy eax and ecx so we will save these before the call and
        # restore them afterwards.

        push    %rax                    # caller-save register
        push    %rcx                    # caller-save register

        mov     $format, %rdi           # set 1st parameter (format)
        mov     %rax, %rsi              # set 2nd parameter (current_number)
        xor     %rax, %rax              # because printf is varargs

        # Stack is already aligned because we pushed three 8 byte registers
        call    printf                  # printf(format, current_number)

        pop     %rcx                    # restore caller-save register
        pop     %rax                    # restore caller-save register

        mov     %rax, %rdx              # save the current number
        mov     %rbx, %rax              # next number is now current
        add     %rdx, %rbx              # get the new next number
        dec     %ecx                    # count down
        jnz     print                   # if not done counting, do some more

        pop     %rbx                    # restore rbx before returning
        ret
format:
        .asciz  "%20ld\n"
#$ gcc fib.s && ./a.out
#                   0
#                   1
#                   1
#                   2
#                   3
#                 ...
#  420196140727489673
#  679891637638612258
# 1100087778366101931
# 1779979416004714189
