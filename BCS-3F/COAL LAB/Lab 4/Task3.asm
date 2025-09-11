TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	valA SBYTE -15
	valB BYTE 25
	valC WORD ?

.code
main proc
	movsx AX, valA
	movsx BX, valB
	add AX, BX
	sub AX, 5

	mov valC, AX
	movsx EAX, valC

	call WriteDec

main ENDP
END main

