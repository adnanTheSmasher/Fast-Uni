TITLE "Adnan Hatim"

include irvine32.inc
.data
	var1 BYTE 20h
	var2 WORD 1000h
	var3 DWORD ?
	var4 BYTE 1, 2, 5, 45, 50
	msg BYTE "File not found", 0
.code
main proc
	mov ax, type var1 
	mov ax, type var2 
	mov ax, type var3 
	mov ax, type var4
	mov ax, type msg
	
	call DumpRegs
	exit

main ENDP
END main