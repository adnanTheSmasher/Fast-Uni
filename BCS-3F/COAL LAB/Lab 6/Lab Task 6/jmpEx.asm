TITLE "Adnan Hatim 24k-0656"
INCLUDE Irvine32.inc

.data
	greeting BYTE "HELLO",0
	alvida BYTE "TATA BYE BYE",0

.code 
main2 PROC
	mov edx, OFFSET greeting
	call WriteString
	call Crlf

	jmp to_alvida
	call Crlf
	mov edx, OFFSET alvida 
	call WriteString

	to_alvida:
		exit


main2 ENDP
END main2