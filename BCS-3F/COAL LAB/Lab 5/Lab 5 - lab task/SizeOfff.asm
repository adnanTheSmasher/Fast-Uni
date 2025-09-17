TITLE "Adnan Hatim"

include irvine32.inc
.data
	intArray WORD 32 DUP(0)
.code
main proc
	mov eax,SIZEOF intArray
	call WriteDec
	exit

main ENDP
END main