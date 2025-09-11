TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	x WORD 12h
	y WORD 14h
	z WORD 5h
	w WORD 10h
	FinalResult WORD ?
.code
main proc
	mov AX, x
	add AX, y
	mov BX, z
	add BX, w
	sub AX, BX
	
	mov FinalResult, AX
	movsx EAX, FinalResult
	call WriteHex
	call Crlf
	call WriteDec


main ENDP
END main

