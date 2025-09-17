TITLE "Adnan Hatim"

include irvine32.inc
.data
	var1 BYTE ?
	var2 WORD ?
	var3 DWORD ?
	var4 DWORD ?
.code
main proc
	mov esi, OFFSET var1
	mov esi, OFFSET var2 
	mov esi, OFFSET var3 
	mov esi, OFFSET var4
	
	call DumpRegs
	exit

main ENDP
END main