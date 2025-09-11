INCLUDE Irvine32.inc
.data
	default_value DWORD 10
	num1 DWORD 4C2h
	num2 DWORD 72o
	num3 DWORD 55d
	num4 DWORD 11101011b
	num5 DWORD 180


.code
main proc
	mov ebx, default_value

	mov eax, num1
	sub eax, ebx
	add eax, num2
	add eax, num3
	sub eax,  num4
	add eax, num5
	
	call WriteDec  


main ENDP
END main

