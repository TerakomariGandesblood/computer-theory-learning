	.file	"main.c"
	.text
	.globl	gets
	.type	gets, @function
gets:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	movq	%rdi, %rbx
.L2:
	movq	stdin(%rip), %rdi
	call	_IO_getc
	cmpl	$10, %eax
	je	.L3
	cmpl	$-1, %eax
	je	.L3
	movb	%al, (%rbx)
	leaq	1(%rbx), %rbx
	jmp	.L2
.L3:
	cmpl	$-1, %eax
	sete	%dl
	cmpq	%rbp, %rbx
	sete	%al
	testb	%al, %dl
	jne	.L6
	movb	$0, (%rbx)
	movq	%rbp, %rax
.L1:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	movl	$0, %eax
	jmp	.L1
	.cfi_endproc
.LFE3:
	.size	gets, .-gets
	.globl	echo
	.type	echo, @function
echo:
.LFB4:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movl	$40, %ebx
	movq	%fs:(%rbx), %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdi
	call	gets
	movq	%rsp, %rdi
	call	puts
	movq	8(%rsp), %rax
	xorq	%fs:(%rbx), %rax
	jne	.L11
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L11:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE4:
	.size	echo, .-echo
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
