INCLUDE Irvine32.inc
.data
	default_value DWORD 10
	num1 DWORD 3
	num2 DWORD 12h
	num3 DWORD 45o
	num4 DWORD 89d


.code
main proc
	mov eax, default_value
	mov ebx, default_value
	mov ecx, default_value

	mov edx, eax
	add edx, num1
	add edx, ebx
	sub edx, ecx
	add edx,  num2
	sub edx, num3
	add edx, num4
	
	xchg eax, edx
	call WriteDec  
	xchg eax, edx

main ENDP
END main

