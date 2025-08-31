INCLUDE Irvine32.inc
.data
default_value DWORD 10
num1 DWORD 101011010110b
num2 DWORD 3Ah
num3 DWORD 64o
num4 DWORD 5



.code
main proc
mov ebx, default_value
mov ecx, default_value

mov ecx, num1
add ecx, num2
sub ecx, num3
add ecx, ebx
sub ecx, ecx
add ecx, num4

xchg eax, ecx
call WriteDec
xchg eax, ecx

main ENDP
END main

