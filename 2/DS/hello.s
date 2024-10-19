.section .rodata
outstring:
.asciz "Hello World! AS version\n"
.section .text
.type _start, @function
.globl _start
_start:
 pushq %rbp
movq %rsp, %rbp
 movq $1, %rax # system call 1 is write
 movq $1, %rdi # file handler 1 is stdout
 movq $outstring, %rsi # address of string to output
 movq $26, %rdx # number of bytes
 syscall
 # exit(0)
 movq $60, %rax # system call 60 is exit
 xorq %rdi, %rdi # we want to return code 0
 popq %rbp
 syscall
