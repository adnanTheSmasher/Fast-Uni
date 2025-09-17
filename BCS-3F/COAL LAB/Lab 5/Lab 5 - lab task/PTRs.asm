TITLE "Adnan Hatim"

include irvine32.inc
.data
	var1 DWORD 12345678h
.code
main proc
	mov ax, WORD PTR var1
	mov ax, WORD PTR [var1 + 2]
	mov bl, BYTE PTR var1
	
	call DumpRegs
	exit

main ENDP
END main