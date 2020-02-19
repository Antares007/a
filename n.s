	.text
	.file	"n.c"
	.globl	noop                    # -- Begin function noop
	.p2align	4, 0x90
	.type	noop,@function
noop:                                   # @noop
.Lnoop$local:
	.cfi_startproc
# %bb.0:
	retq
.Lfunc_end0:
	.size	noop, .Lfunc_end0-noop
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
	.globl	Tplus                   # -- Begin function Tplus
	.p2align	4, 0x90
	.type	Tplus,@function
Tplus:                                  # @Tplus
.LTplus$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r9
	movl	$.L.str, %esi
	movl	$.LTplus$local, %edx
	movl	$.Lplus$local, %ecx
	movq	%rax, %rdi
	xorl	%r8d, %r8d
	jmpq	*%r9                    # TAILCALL
.Lfunc_end6:
	.size	Tplus, .Lfunc_end6-Tplus
	.cfi_endproc
                                        # -- End function
	.globl	Tmul                    # -- Begin function Tmul
	.p2align	4, 0x90
	.type	Tmul,@function
Tmul:                                   # @Tmul
.LTmul$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r9
	movl	$.L.str.1, %esi
	movl	$.LTmul$local, %edx
	movl	$.Lmul$local, %ecx
	movq	%rax, %rdi
	xorl	%r8d, %r8d
	jmpq	*%r9                    # TAILCALL
.Lfunc_end7:
	.size	Tmul, .Lfunc_end7-Tmul
	.cfi_endproc
                                        # -- End function
	.globl	Tlparen                 # -- Begin function Tlparen
	.p2align	4, 0x90
	.type	Tlparen,@function
Tlparen:                                # @Tlparen
.LTlparen$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r9
	movl	$.L.str.2, %esi
	movl	$.LTlparen$local, %edx
	movl	$.Llparen$local, %ecx
	movq	%rax, %rdi
	xorl	%r8d, %r8d
	jmpq	*%r9                    # TAILCALL
.Lfunc_end8:
	.size	Tlparen, .Lfunc_end8-Tlparen
	.cfi_endproc
                                        # -- End function
	.globl	Trparen                 # -- Begin function Trparen
	.p2align	4, 0x90
	.type	Trparen,@function
Trparen:                                # @Trparen
.LTrparen$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r9
	movl	$.L.str.3, %esi
	movl	$.LTrparen$local, %edx
	movl	$.Lrparen$local, %ecx
	movq	%rax, %rdi
	xorl	%r8d, %r8d
	jmpq	*%r9                    # TAILCALL
.Lfunc_end9:
	.size	Trparen, .Lfunc_end9-Trparen
	.cfi_endproc
                                        # -- End function
	.globl	Tid                     # -- Begin function Tid
	.p2align	4, 0x90
	.type	Tid,@function
Tid:                                    # @Tid
.LTid$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r9
	movl	$.L.str.4, %esi
	movl	$.LTid$local, %edx
	movl	$.Lid$local, %ecx
	movq	%rax, %rdi
	xorl	%r8d, %r8d
	jmpq	*%r9                    # TAILCALL
.Lfunc_end10:
	.size	Tid, .Lfunc_end10-Tid
	.cfi_endproc
                                        # -- End function
	.globl	Gnoop                   # -- Begin function Gnoop
	.p2align	4, 0x90
	.type	Gnoop,@function
Gnoop:                                  # @Gnoop
.LGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rax
	movq	%rdi, %r9
	movl	$.L.str.5, %esi
	movl	$.LGnoop$local, %edx
	movl	$.Lnoop$local, %ecx
	movq	%rax, %rdi
	xorl	%r8d, %r8d
	jmpq	*%r9                    # TAILCALL
.Lfunc_end11:
	.size	Gnoop, .Lfunc_end11-Gnoop
	.cfi_endproc
                                        # -- End function
	.globl	CtermGnoop              # -- Begin function CtermGnoop
	.p2align	4, 0x90
	.type	CtermGnoop,@function
CtermGnoop:                             # @CtermGnoop
.LCtermGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.6, %esi
	movl	$.LCtermGnoop$local, %edx
	movl	$.Lterm$local, %ecx
	movl	$.LGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end12:
	.size	CtermGnoop, .Lfunc_end12-CtermGnoop
	.cfi_endproc
                                        # -- End function
	.globl	term                    # -- Begin function term
	.p2align	4, 0x90
	.type	term,@function
term:                                   # @term
.Lterm$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.13, %esi
	movl	$.Lterm$local, %edx
	movl	$.LCtermCTmulCfactorGnoop$local, %ecx
	movl	$.LCfactorGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end13:
	.size	term, .Lfunc_end13-term
	.cfi_endproc
                                        # -- End function
	.globl	CTplusCtermGnoop        # -- Begin function CTplusCtermGnoop
	.p2align	4, 0x90
	.type	CTplusCtermGnoop,@function
CTplusCtermGnoop:                       # @CTplusCtermGnoop
.LCTplusCtermGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.7, %esi
	movl	$.LCTplusCtermGnoop$local, %edx
	movl	$.LTplus$local, %ecx
	movl	$.LCtermGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end14:
	.size	CTplusCtermGnoop, .Lfunc_end14-CTplusCtermGnoop
	.cfi_endproc
                                        # -- End function
	.globl	CexprCTplusCtermGnoop   # -- Begin function CexprCTplusCtermGnoop
	.p2align	4, 0x90
	.type	CexprCTplusCtermGnoop,@function
CexprCTplusCtermGnoop:                  # @CexprCTplusCtermGnoop
.LCexprCTplusCtermGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.8, %esi
	movl	$.LCexprCTplusCtermGnoop$local, %edx
	movl	$.Lexpr$local, %ecx
	movl	$.LCTplusCtermGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end15:
	.size	CexprCTplusCtermGnoop, .Lfunc_end15-CexprCTplusCtermGnoop
	.cfi_endproc
                                        # -- End function
	.globl	expr                    # -- Begin function expr
	.p2align	4, 0x90
	.type	expr,@function
expr:                                   # @expr
.Lexpr$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.9, %esi
	movl	$.Lexpr$local, %edx
	movl	$.LCexprCTplusCtermGnoop$local, %ecx
	movl	$.LCtermGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end16:
	.size	expr, .Lfunc_end16-expr
	.cfi_endproc
                                        # -- End function
	.globl	CfactorGnoop            # -- Begin function CfactorGnoop
	.p2align	4, 0x90
	.type	CfactorGnoop,@function
CfactorGnoop:                           # @CfactorGnoop
.LCfactorGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.10, %esi
	movl	$.LCfactorGnoop$local, %edx
	movl	$.Lfactor$local, %ecx
	movl	$.LGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end17:
	.size	CfactorGnoop, .Lfunc_end17-CfactorGnoop
	.cfi_endproc
                                        # -- End function
	.globl	factor                  # -- Begin function factor
	.p2align	4, 0x90
	.type	factor,@function
factor:                                 # @factor
.Lfactor$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.18, %esi
	movl	$.Lfactor$local, %edx
	movl	$.LCTlparenCexprCTrparenGnoop$local, %ecx
	movl	$.LCTidGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end18:
	.size	factor, .Lfunc_end18-factor
	.cfi_endproc
                                        # -- End function
	.globl	CTmulCfactorGnoop       # -- Begin function CTmulCfactorGnoop
	.p2align	4, 0x90
	.type	CTmulCfactorGnoop,@function
CTmulCfactorGnoop:                      # @CTmulCfactorGnoop
.LCTmulCfactorGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.11, %esi
	movl	$.LCTmulCfactorGnoop$local, %edx
	movl	$.LTmul$local, %ecx
	movl	$.LCfactorGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end19:
	.size	CTmulCfactorGnoop, .Lfunc_end19-CTmulCfactorGnoop
	.cfi_endproc
                                        # -- End function
	.globl	CtermCTmulCfactorGnoop  # -- Begin function CtermCTmulCfactorGnoop
	.p2align	4, 0x90
	.type	CtermCTmulCfactorGnoop,@function
CtermCTmulCfactorGnoop:                 # @CtermCTmulCfactorGnoop
.LCtermCTmulCfactorGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.12, %esi
	movl	$.LCtermCTmulCfactorGnoop$local, %edx
	movl	$.Lterm$local, %ecx
	movl	$.LCTmulCfactorGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end20:
	.size	CtermCTmulCfactorGnoop, .Lfunc_end20-CtermCTmulCfactorGnoop
	.cfi_endproc
                                        # -- End function
	.globl	CTrparenGnoop           # -- Begin function CTrparenGnoop
	.p2align	4, 0x90
	.type	CTrparenGnoop,@function
CTrparenGnoop:                          # @CTrparenGnoop
.LCTrparenGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.14, %esi
	movl	$.LCTrparenGnoop$local, %edx
	movl	$.LTrparen$local, %ecx
	movl	$.LGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end21:
	.size	CTrparenGnoop, .Lfunc_end21-CTrparenGnoop
	.cfi_endproc
                                        # -- End function
	.globl	CexprCTrparenGnoop      # -- Begin function CexprCTrparenGnoop
	.p2align	4, 0x90
	.type	CexprCTrparenGnoop,@function
CexprCTrparenGnoop:                     # @CexprCTrparenGnoop
.LCexprCTrparenGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.15, %esi
	movl	$.LCexprCTrparenGnoop$local, %edx
	movl	$.Lexpr$local, %ecx
	movl	$.LCTrparenGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end22:
	.size	CexprCTrparenGnoop, .Lfunc_end22-CexprCTrparenGnoop
	.cfi_endproc
                                        # -- End function
	.globl	CTlparenCexprCTrparenGnoop # -- Begin function CTlparenCexprCTrparenGnoop
	.p2align	4, 0x90
	.type	CTlparenCexprCTrparenGnoop,@function
CTlparenCexprCTrparenGnoop:             # @CTlparenCexprCTrparenGnoop
.LCTlparenCexprCTrparenGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.16, %esi
	movl	$.LCTlparenCexprCTrparenGnoop$local, %edx
	movl	$.LTlparen$local, %ecx
	movl	$.LCexprCTrparenGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end23:
	.size	CTlparenCexprCTrparenGnoop, .Lfunc_end23-CTlparenCexprCTrparenGnoop
	.cfi_endproc
                                        # -- End function
	.globl	CTidGnoop               # -- Begin function CTidGnoop
	.p2align	4, 0x90
	.type	CTidGnoop,@function
CTidGnoop:                              # @CTidGnoop
.LCTidGnoop$local:
	.cfi_startproc
# %bb.0:
	movq	%rsi, %r9
	movq	%rdi, %rax
	movl	$.L.str.17, %esi
	movl	$.LCTidGnoop$local, %edx
	movl	$.LTid$local, %ecx
	movl	$.LGnoop$local, %r8d
	movq	%r9, %rdi
	jmpq	*%rax                   # TAILCALL
.Lfunc_end24:
	.size	CTidGnoop, .Lfunc_end24-CTidGnoop
	.cfi_endproc
                                        # -- End function
	.globl	print                   # -- Begin function print
	.p2align	4, 0x90
	.type	print,@function
print:                                  # @print
.Lprint$local:
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %rbp, -16
	movq	%rsi, %rbx
	testl	%edi, %edi
	je	.LBB25_3
# %bb.1:
	movl	%edi, %ebp
	.p2align	4, 0x90
.LBB25_2:                               # =>This Inner Loop Header: Depth=1
	movl	$.L.str.19, %edi
	xorl	%eax, %eax
	callq	printf
	addl	$-1, %ebp
	jne	.LBB25_2
.LBB25_3:
	movq	%rbx, %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	puts                    # TAILCALL
.Lfunc_end25:
	.size	print, .Lfunc_end25-print
	.cfi_endproc
                                        # -- End function
	.globl	avl_ring                # -- Begin function avl_ring
	.p2align	4, 0x90
	.type	avl_ring,@function
avl_ring:                               # @avl_ring
.Lavl_ring$local:
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movq	%rdi, %rbx
	movl	$0, (%rsp)
	movq	%rdi, 8(%rsp)
	movl	$.Lexpr$local, %esi
	movl	$.Lexpr$local, %edx
	callq	avl_insert
	movl	$.L.str.9, %edi
	callq	puts
	movl	$.LCexprCTplusCtermGnoop$local, %esi
	movq	%rbx, %rdi
	callq	avl_search
	testq	%rax, %rax
	jne	.LBB26_2
# %bb.1:
	movl	$1, (%rsp)
	movq	%rsp, %rdi
	movl	$.L.str.8, %esi
	movl	$.LCexprCTplusCtermGnoop$local, %edx
	movl	$.Lexpr$local, %ecx
	movl	$.LCTplusCtermGnoop$local, %r8d
	callq	print_pith
	addl	$-1, (%rsp)
.LBB26_2:
	movq	%rsp, %rdi
	movl	$.L.str.6, %esi
	movl	$.LCtermGnoop$local, %edx
	movl	$.Lterm$local, %ecx
	movl	$.LGnoop$local, %r8d
	callq	print_pith
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end26:
	.size	avl_ring, .Lfunc_end26-avl_ring
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lmain$local:
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$.L.str.21, %edi
	xorl	%esi, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lavl_ring$local, %edi
	movl	$avl_ptrcmp, %esi
	movl	$avl_void_key_destructor, %edx
	movl	$avl_void_value_destructor, %ecx
	callq	avl_bark
	movl	$9, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end27:
	.size	main, .Lfunc_end27-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Tplus"
	.size	.L.str, 6

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Tmul"
	.size	.L.str.1, 5

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Tlparen"
	.size	.L.str.2, 8

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Trparen"
	.size	.L.str.3, 8

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"Tid"
	.size	.L.str.4, 4

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"Gnoop"
	.size	.L.str.5, 6

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"CtermGnoop"
	.size	.L.str.6, 11

	.type	.L.str.7,@object        # @.str.7
.L.str.7:
	.asciz	"CTplusCtermGnoop"
	.size	.L.str.7, 17

	.type	.L.str.8,@object        # @.str.8
.L.str.8:
	.asciz	"CexprCTplusCtermGnoop"
	.size	.L.str.8, 22

	.type	.L.str.9,@object        # @.str.9
.L.str.9:
	.asciz	"expr"
	.size	.L.str.9, 5

	.type	.L.str.10,@object       # @.str.10
.L.str.10:
	.asciz	"CfactorGnoop"
	.size	.L.str.10, 13

	.type	.L.str.11,@object       # @.str.11
.L.str.11:
	.asciz	"CTmulCfactorGnoop"
	.size	.L.str.11, 18

	.type	.L.str.12,@object       # @.str.12
.L.str.12:
	.asciz	"CtermCTmulCfactorGnoop"
	.size	.L.str.12, 23

	.type	.L.str.13,@object       # @.str.13
.L.str.13:
	.asciz	"term"
	.size	.L.str.13, 5

	.type	.L.str.14,@object       # @.str.14
.L.str.14:
	.asciz	"CTrparenGnoop"
	.size	.L.str.14, 14

	.type	.L.str.15,@object       # @.str.15
.L.str.15:
	.asciz	"CexprCTrparenGnoop"
	.size	.L.str.15, 19

	.type	.L.str.16,@object       # @.str.16
.L.str.16:
	.asciz	"CTlparenCexprCTrparenGnoop"
	.size	.L.str.16, 27

	.type	.L.str.17,@object       # @.str.17
.L.str.17:
	.asciz	"CTidGnoop"
	.size	.L.str.17, 10

	.type	.L.str.18,@object       # @.str.18
.L.str.18:
	.asciz	"factor"
	.size	.L.str.18, 7

	.type	.L.str.19,@object       # @.str.19
.L.str.19:
	.asciz	". . "
	.size	.L.str.19, 5

	.type	.L.str.21,@object       # @.str.21
.L.str.21:
	.asciz	"%d"
	.size	.L.str.21, 3

	.ident	"clang version 11.0.0 (https://github.com/llvm/llvm-project.git adc02174165e69f653a21c541221bdbbaab90427)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym noop
	.addrsig_sym id
	.addrsig_sym plus
	.addrsig_sym mul
	.addrsig_sym lparen
	.addrsig_sym rparen
	.addrsig_sym Tplus
	.addrsig_sym Tmul
	.addrsig_sym Tlparen
	.addrsig_sym Trparen
	.addrsig_sym Tid
	.addrsig_sym Gnoop
	.addrsig_sym CtermGnoop
	.addrsig_sym term
	.addrsig_sym CTplusCtermGnoop
	.addrsig_sym CexprCTplusCtermGnoop
	.addrsig_sym expr
	.addrsig_sym CfactorGnoop
	.addrsig_sym factor
	.addrsig_sym CTmulCfactorGnoop
	.addrsig_sym CtermCTmulCfactorGnoop
	.addrsig_sym CTrparenGnoop
	.addrsig_sym CexprCTrparenGnoop
	.addrsig_sym CTlparenCexprCTrparenGnoop
	.addrsig_sym CTidGnoop
	.addrsig_sym avl_ring
	.addrsig_sym avl_ptrcmp
	.addrsig_sym avl_void_key_destructor
	.addrsig_sym avl_void_value_destructor
