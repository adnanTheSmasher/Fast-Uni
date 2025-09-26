TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc
.data
	
.code
main proc
	mov EAX, 15000
	ADD EAX, 1

	call DumpRegs
	
	exit
main ENDP
END main