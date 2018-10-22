.data

.text
    .global _start

_start:
    movl %eax,%rax

    movq $0,%rbx
    movq $1,%rax
    int  $0x80
