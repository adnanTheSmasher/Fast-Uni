TITLE "Adnan Hatim 24k-0656"
INCLUDE Irvine32.inc

.data
	count DWORD 20


.code 
main3 PROC
	mov ecx, count 
	mov eax, 1

	Printing:
		call WriteDec
		call Crlf
		inc eax 
		loop Printing 


main3 ENDP
END main3