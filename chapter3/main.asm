.data

.text
    .global _start

_start:
    movl %eax,%rax


    movq $0,%rbx     # 参数一：退出代码
    movq $1,%rax     # 系统调用号(sys_exit)
    int  $0x80       # 调用内核功能
