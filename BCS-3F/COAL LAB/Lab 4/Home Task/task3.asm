TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	dayTemp WORD 30
	nightTemp WORD 18

.code
main proc
	mov AX, dayTemp
	sub AX, nightTemp
	INC AX

	movzx EAX, AX
	call WriteDec

exit
main ENDP
END main