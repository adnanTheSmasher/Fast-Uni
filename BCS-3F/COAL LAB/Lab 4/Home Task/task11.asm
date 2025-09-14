TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	val1 BYTE 10h
	val2 WORD 8000h
	val3 DWORD 0FFFFh
	val4 WORD 7FFFh
	msg1 BYTE "After incrementing val2: ", 0
	msg2 BYTE "After subtracting val3 from EAX: ", 0
	msg3 BYTE "After subtracting val4 from val2: ", 0
	msg4 BYTE "Value of BL after moving val1: ", 0

.code
main proc
	INC val2
	movzx EAX, val2
	mov EDX, OFFSET msg1
	call WriteString
	call WriteHex

	call Crlf

	sub EAX, val3
	mov EDX, OFFSET msg2
	call WriteString
	call WriteHex
	call Crlf

	mov AX, val2
	sub AX, val4
	movzx EAX, AX
	mov EDX, OFFSET msg3
	call WriteString
	call WriteDec
	call Crlf

	mov BL, val1
	mov EDX, OFFSET msg4
	call WriteString
	call WriteHex
	call Crlf


	exit
main ENDP
END main