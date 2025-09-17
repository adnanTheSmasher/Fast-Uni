TITLE "Adnan Hatim"

include irvine32.inc
.data
	byte1 BYTE 10,20,30
	array1 WORD 30 DUP(?),0,0
	array2 WORD 5 DUP(3 DUP(?))
	array3 DWORD 1,2,3,4
	string BYTE "12345678",0
.code
main proc
	mov eax, LENGTHOF byte1
	call writeDec
	call Crlf

	mov eax, LENGTHOF array1
	call writeDec
	call Crlf
	
	mov eax, LENGTHOF array2
	call writeDec
	call Crlf

	mov eax, LENGTHOF string
	call writeDec
	call Crlf

	exit

main ENDP
END main