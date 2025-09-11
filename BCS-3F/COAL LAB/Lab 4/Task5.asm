TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	num1 WORD 1234h
	num2 WORD 5678h

.code
main proc
	mov AX, num1
	mov BX, num2
	xchg AX, BX
	
	mov num1, AX
	mov num2, BX
	
	movzx EAX, num1
	call WriteDec
	call Crlf

	movzx EAX, num2
	call WriteDec
	call Crlf
main ENDP
END main

