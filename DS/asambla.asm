

section .data
Hallo DB "Hallo"
A DD 12h
section .text
global CMAIN
CMAIN:
 mov ebp, esp ; for correct debugging
 ;write your code here
 xor eax, eax
 MOV EAX, [A]
 MOV EBX, 12
 ADD EAX, EBX

 xor eax, eax
 ret