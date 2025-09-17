TITLE "Adnan Hatim"

include irvine32.inc
.data
	array WORD 12, 15, 16
.code
main PROC

	mov esi, 1
	mov ax, array[esi * TYPE array] ; 
	mov esi, 2
	mov bx, array[esi * TYPE array] ;
	mov esi, 3
	mov cx, array[esi * TYPE array] ; 
	call DumpRegs
	exit

main ENDP
END main