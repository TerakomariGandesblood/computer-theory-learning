	.file	"main.c"
	.text
	.globl	fuck
	.type	fuck, @function
fuck:
.LFB0:
	.cfi_startproc
	leaq	(%rdi,%rsi,4), %rax
	leaq	(%rdx,%rdx,2), %rcx
	leaq	0(,%rcx,4), %rdx
	addq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	fuck, .-fuck
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
