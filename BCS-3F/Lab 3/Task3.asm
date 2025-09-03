TITLE Adnan 24K-0656(Source.asm)
INCLUDE Irvine32.inc
.data
	
	num1 DWORD 500
	num2 DWORD 200


.code
main proc
	mov eax, num1
	add eax, num2
	call WriteDec

main ENDP
END main