TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

PI = 3

.data
	

.code
main proc
	
	mov EAX, 4
	IMUL EAX, PI
	call WriteDec


exit
main ENDP
END main