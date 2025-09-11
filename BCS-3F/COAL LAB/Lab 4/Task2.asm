TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

COUNT = 5
LIMIT EQU 10

.data
	Result WORD ?

.code
main proc

	mov AX, COUNT
	add AX, LIMIT
	INC AX

	mov Result, AX
	movzx EAX, Result
	call WriteDec


main ENDP
END main

