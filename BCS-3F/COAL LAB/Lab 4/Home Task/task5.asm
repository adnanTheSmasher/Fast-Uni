TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	var SBYTE -10

.code
main proc
	mov AL, var 
	movzx AX, AL
	movzx EAX, AX
	call WriteDec

	call Crlf

	mov AL, var 
	movsx EAX, AL
	call WriteInt

exit
main ENDP
END main