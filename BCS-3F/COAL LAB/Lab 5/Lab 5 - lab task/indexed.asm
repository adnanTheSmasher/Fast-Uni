TITLE "Adnan Hatim"

include irvine32.inc
.data
	array WORD 12, 15, 16
.code
main PROC
	mov esi, OFFSET array
	mov ax, [esi] 
	mov bx, [esi+2] 
	mov cx, [esi+4] 	
	call DumpRegs
	exit

main ENDP
END main