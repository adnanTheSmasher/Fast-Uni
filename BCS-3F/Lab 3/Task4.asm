TITLE Adnan 24K-0656(Source.asm)
INCLUDE Irvine32.inc
.data
	
	num1 DWORD 90
	num2 DWORD 5Ah
	num3 DWORD 01011010b
	num4 DWORD 66


.code
main proc
	mov ebx, num1
	add ebx, num2
	add ebx, num3
	add ebx, num4
	
	mov eax, ebx
	call WriteDec

main ENDP
END main