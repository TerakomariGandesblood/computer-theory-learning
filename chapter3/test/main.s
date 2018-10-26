	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
#APP
# 4 "main.c" 1
	xorl %eax,%eax;
# 0 "" 2
#NO_APP
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
