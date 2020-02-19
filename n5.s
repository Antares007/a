	.text
	.file	"n5.c"
	.globl	_                       # -- Begin function _
	.p2align	4, 0x90
	.type	_,@function
_:                                      # @_
.L_$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end0:
	.size	_, .Lfunc_end0-_
	.cfi_endproc
                                        # -- End function
	.globl	id                      # -- Begin function id
	.p2align	4, 0x90
	.type	id,@function
id:                                     # @id
.Lid$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end1:
	.size	id, .Lfunc_end1-id
	.cfi_endproc
                                        # -- End function
	.globl	plus                    # -- Begin function plus
	.p2align	4, 0x90
	.type	plus,@function
plus:                                   # @plus
.Lplus$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end2:
	.size	plus, .Lfunc_end2-plus
	.cfi_endproc
                                        # -- End function
	.globl	mul                     # -- Begin function mul
	.p2align	4, 0x90
	.type	mul,@function
mul:                                    # @mul
.Lmul$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end3:
	.size	mul, .Lfunc_end3-mul
	.cfi_endproc
                                        # -- End function
	.globl	lparen                  # -- Begin function lparen
	.p2align	4, 0x90
	.type	lparen,@function
lparen:                                 # @lparen
.Llparen$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end4:
	.size	lparen, .Lfunc_end4-lparen
	.cfi_endproc
                                        # -- End function
	.globl	rparen                  # -- Begin function rparen
	.p2align	4, 0x90
	.type	rparen,@function
rparen:                                 # @rparen
.Lrparen$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end5:
	.size	rparen, .Lfunc_end5-rparen
	.cfi_endproc
                                        # -- End function
	.globl	t22                     # -- Begin function t22
	.p2align	4, 0x90
	.type	t22,@function
t22:                                    # @t22
.Lt22$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r8
	movl	$.L.str, %esi
	movl	$.L_$local, %edx
	movq	%rax, %rdi
	xorl	%ecx, %ecx
	jmpq	*%r8                    # TAILCALL
.Lfunc_end6:
	.size	t22, .Lfunc_end6-t22
	.cfi_endproc
                                        # -- End function
	.globl	t23                     # -- Begin function t23
	.p2align	4, 0x90
	.type	t23,@function
t23:                                    # @t23
.Lt23$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.1, %esi
	movl	$.Lid$local, %edx
	movl	$.Lt22$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end7:
	.size	t23, .Lfunc_end7-t23
	.cfi_endproc
                                        # -- End function
	.globl	t24                     # -- Begin function t24
	.p2align	4, 0x90
	.type	t24,@function
t24:                                    # @t24
.Lt24$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str, %esi
	movl	$.L_$local, %edx
	movl	$.Lt23$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end8:
	.size	t24, .Lfunc_end8-t24
	.cfi_endproc
                                        # -- End function
	.globl	t25                     # -- Begin function t25
	.p2align	4, 0x90
	.type	t25,@function
t25:                                    # @t25
.Lt25$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.2, %esi
	movl	$.Lrparen$local, %edx
	movl	$.Lt24$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end9:
	.size	t25, .Lfunc_end9-t25
	.cfi_endproc
                                        # -- End function
	.globl	t26                     # -- Begin function t26
	.p2align	4, 0x90
	.type	t26,@function
t26:                                    # @t26
.Lt26$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.3, %esi
	movl	$.LE$local, %edx
	movl	$.Lt25$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end10:
	.size	t26, .Lfunc_end10-t26
	.cfi_endproc
                                        # -- End function
	.globl	E                       # -- Begin function E
	.p2align	4, 0x90
	.type	E,@function
E:                                      # @E
.LE$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.3, %esi
	movl	$.LE$local, %edx
	movl	$.Lt40$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end11:
	.size	E, .Lfunc_end11-E
	.cfi_endproc
                                        # -- End function
	.globl	F                       # -- Begin function F
	.p2align	4, 0x90
	.type	F,@function
F:                                      # @F
.LF$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.4, %esi
	movl	$.Llparen$local, %edx
	movl	$.Lt26$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end12:
	.size	F, .Lfunc_end12-F
	.cfi_endproc
                                        # -- End function
	.globl	t29                     # -- Begin function t29
	.p2align	4, 0x90
	.type	t29,@function
t29:                                    # @t29
.Lt29$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r8
	movl	$.L.str, %esi
	movl	$.L_$local, %edx
	movq	%rax, %rdi
	xorl	%ecx, %ecx
	jmpq	*%r8                    # TAILCALL
.Lfunc_end13:
	.size	t29, .Lfunc_end13-t29
	.cfi_endproc
                                        # -- End function
	.globl	t30                     # -- Begin function t30
	.p2align	4, 0x90
	.type	t30,@function
t30:                                    # @t30
.Lt30$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.5, %esi
	movl	$.LF$local, %edx
	movl	$.Lt29$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end14:
	.size	t30, .Lfunc_end14-t30
	.cfi_endproc
                                        # -- End function
	.globl	t31                     # -- Begin function t31
	.p2align	4, 0x90
	.type	t31,@function
t31:                                    # @t31
.Lt31$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str, %esi
	movl	$.L_$local, %edx
	movl	$.Lt30$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end15:
	.size	t31, .Lfunc_end15-t31
	.cfi_endproc
                                        # -- End function
	.globl	t32                     # -- Begin function t32
	.p2align	4, 0x90
	.type	t32,@function
t32:                                    # @t32
.Lt32$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.5, %esi
	movl	$.LF$local, %edx
	movl	$.Lt31$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end16:
	.size	t32, .Lfunc_end16-t32
	.cfi_endproc
                                        # -- End function
	.globl	t33                     # -- Begin function t33
	.p2align	4, 0x90
	.type	t33,@function
t33:                                    # @t33
.Lt33$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.6, %esi
	movl	$.Lmul$local, %edx
	movl	$.Lt32$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end17:
	.size	t33, .Lfunc_end17-t33
	.cfi_endproc
                                        # -- End function
	.globl	T                       # -- Begin function T
	.p2align	4, 0x90
	.type	T,@function
T:                                      # @T
.LT$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.7, %esi
	movl	$.LT$local, %edx
	movl	$.Lt33$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end18:
	.size	T, .Lfunc_end18-T
	.cfi_endproc
                                        # -- End function
	.globl	t36                     # -- Begin function t36
	.p2align	4, 0x90
	.type	t36,@function
t36:                                    # @t36
.Lt36$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r8
	movl	$.L.str, %esi
	movl	$.L_$local, %edx
	movq	%rax, %rdi
	xorl	%ecx, %ecx
	jmpq	*%r8                    # TAILCALL
.Lfunc_end19:
	.size	t36, .Lfunc_end19-t36
	.cfi_endproc
                                        # -- End function
	.globl	t37                     # -- Begin function t37
	.p2align	4, 0x90
	.type	t37,@function
t37:                                    # @t37
.Lt37$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.7, %esi
	movl	$.LT$local, %edx
	movl	$.Lt36$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end20:
	.size	t37, .Lfunc_end20-t37
	.cfi_endproc
                                        # -- End function
	.globl	t38                     # -- Begin function t38
	.p2align	4, 0x90
	.type	t38,@function
t38:                                    # @t38
.Lt38$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str, %esi
	movl	$.L_$local, %edx
	movl	$.Lt37$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end21:
	.size	t38, .Lfunc_end21-t38
	.cfi_endproc
                                        # -- End function
	.globl	t39                     # -- Begin function t39
	.p2align	4, 0x90
	.type	t39,@function
t39:                                    # @t39
.Lt39$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.7, %esi
	movl	$.LT$local, %edx
	movl	$.Lt38$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end22:
	.size	t39, .Lfunc_end22-t39
	.cfi_endproc
                                        # -- End function
	.globl	t40                     # -- Begin function t40
	.p2align	4, 0x90
	.type	t40,@function
t40:                                    # @t40
.Lt40$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r8
	movq	%rdi, %rax
	movl	$.L.str.8, %esi
	movl	$.Lplus$local, %edx
	movl	$.Lt39$local, %ecx
	movq	%r8, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end23:
	.size	t40, .Lfunc_end23-t40
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"_"
	.size	.L.str, 2

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"id"
	.size	.L.str.1, 3

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"rparen"
	.size	.L.str.2, 7

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"E"
	.size	.L.str.3, 2

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"lparen"
	.size	.L.str.4, 7

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"F"
	.size	.L.str.5, 2

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"mul"
	.size	.L.str.6, 4

	.type	.L.str.7,@object        # @.str.7
.L.str.7:
	.asciz	"T"
	.size	.L.str.7, 2

	.type	.L.str.8,@object        # @.str.8
.L.str.8:
	.asciz	"plus"
	.size	.L.str.8, 5

	.ident	"clang version 11.0.0 (https://github.com/llvm/llvm-project.git adc02174165e69f653a21c541221bdbbaab90427)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _
	.addrsig_sym id
	.addrsig_sym plus
	.addrsig_sym mul
	.addrsig_sym lparen
	.addrsig_sym rparen
	.addrsig_sym t22
	.addrsig_sym t23
	.addrsig_sym t24
	.addrsig_sym t25
	.addrsig_sym t26
	.addrsig_sym E
	.addrsig_sym F
	.addrsig_sym t29
	.addrsig_sym t30
	.addrsig_sym t31
	.addrsig_sym t32
	.addrsig_sym t33
	.addrsig_sym T
	.addrsig_sym t36
	.addrsig_sym t37
	.addrsig_sym t38
	.addrsig_sym t39
	.addrsig_sym t40
