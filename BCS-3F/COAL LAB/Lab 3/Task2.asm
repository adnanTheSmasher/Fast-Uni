INCLUDE Irvine32.inc
.data

	message BYTE "Hello World", 0

.code
main proc
	mov edx, OFFSET message
	call Writestring

main ENDP
END main