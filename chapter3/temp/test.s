.data
str:.asciz "The value is %d\n"

.text
.global main

main:
    subq $8,%rsp

    movq $str,%rdi
    movq $10,%rsi

    callq printf

    addq $8,%rsp
