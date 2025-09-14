TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	mark1 WORD 45
	mark2 WORD 35
	

.code
main proc
	mov AX, mark1
	add AX, mark2

	movzx EAX, AX
	call WriteDec

	call Crlf

	mov AX, mark1
	sub AX, mark2

	movzx EAX, AX
	call WriteDec

exit
main ENDP
END main