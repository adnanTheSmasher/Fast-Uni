TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	items WORD 50

.code
main proc
	mov AX, items
	sub AX, 7
	add AX, 15

	movzx EAX, AX
	call WriteDec

exit
main ENDP
END main