TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	accountBalance WORD 5000

.code
main proc
	mov AX, accountBalance
	add AX, 1200
	sub AX, 2000

	movzx EAX, AX
	call WriteDec

exit
main ENDP
END main