TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc
.data
.code
main proc
	
	mov AX, 10
	mov BX, 20

	XCHG AX, BX
	
exit
main ENDP
END main