TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

SecondsInDay = (20 * 60 * 60)

.data
.code
main proc
	
	mov EAX, SecondsInDay
	call WriteDec
	
exit
main ENDP
END main