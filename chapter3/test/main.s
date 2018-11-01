	.file	"main.c"
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	movsbq	8(%rsp), %rax
	movq	%rax, (%rsi)
	movswl	%r8w, %r8d
	movl	%r8d, (%rcx)
	movw	%dx, (%r9)
	movq	16(%rsp), %rax
	movb	%dil, (%rax)
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
	.globl	call_proc
	.type	call_proc, @function
call_proc:
.LFB1:
	.cfi_startproc
	subq	$16, %rsp
	.cfi_def_cfa_offset 24
	movq	$1, 8(%rsp)
	movl	$2, 4(%rsp)
	movw	$3, 2(%rsp)
	movb	$4, 1(%rsp)
	leaq	1(%rsp), %rax
	pushq	%rax
	.cfi_def_cfa_offset 32
	pushq	$4
	.cfi_def_cfa_offset 40
	leaq	18(%rsp), %r9
	movl	$3, %r8d
	leaq	20(%rsp), %rcx
	movl	$2, %edx
	leaq	24(%rsp), %rsi
	movl	$1, %edi
	call	proc
	movslq	20(%rsp), %rax
	addq	24(%rsp), %rax
	movswl	18(%rsp), %edx
	movsbl	17(%rsp), %ecx
	subl	%ecx, %edx
	movslq	%edx, %rdx
	imulq	%rdx, %rax
	addq	$32, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	call_proc, .-call_proc
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
