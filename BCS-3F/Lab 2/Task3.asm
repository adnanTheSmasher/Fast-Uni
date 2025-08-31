INCLUDE Irvine32.inc
.data
	default_value DWORD 10
	num1 DWORD 6F1h
	num2 DWORD 92d
	num3 DWORD 47o
	num4 DWORD 11011001b
	num5 DWORD 6Ch


.code
main proc
	mov eax, default_value

	mov ebx, num1
	sub ebx, eax
	add ebx, num2
	add ebx, num3
	sub ebx,  num4
	add ebx, num5
	
	xchg eax, ebx
	call WriteDec  
	xchg eax, ebx

main ENDP
END main

