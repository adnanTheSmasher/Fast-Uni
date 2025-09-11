INCLUDE Irvine32.inc
.data
	num1 DWORD 111b
	num2 DWORD 12
	num3 DWORD 1F3h
	num4 DWORD  745o

.code
main proc
	mov eax, num1
	sub eax, num2
	add eax, num3
	sub eax, num4
	
	call WriteDec  

main ENDP
END main

