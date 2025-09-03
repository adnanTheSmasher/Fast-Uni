TITLE Adnan 24K-0656(Source.asm)
INCLUDE Irvine32.inc

.code
main proc
	mov eax, 300h
	add eax, 600h
	sub eax, 100h
	
	call WriteDec

main ENDP
END main