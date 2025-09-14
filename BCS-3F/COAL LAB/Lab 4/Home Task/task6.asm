TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
	var DWORD 10

.code
main proc
	INC var
	INC var
	INC var

	mov EAX, var
	call WriteDec


exit
main ENDP
END main