TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc
.data
	
.code
main2 proc
	mov AX, 0A7F0h
	add AL, 15h;
	add ah, 1h
	add ax, 2h
	call DumpRegs
	
	exit
main2 ENDP
END main2