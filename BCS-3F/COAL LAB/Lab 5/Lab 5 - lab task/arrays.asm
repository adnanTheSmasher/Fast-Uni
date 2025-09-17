TITLE "Adnan Hatim"

include irvine32.inc
.data
	array DWORD 12, 15, 16
.code
main proc
	mov esi, OFFSET array
	mov EAX, [esi]
	add esi, 4
	mov EAX, [esi]

	call WriteDec
	exit

main ENDP
END main