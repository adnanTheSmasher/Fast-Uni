INCLUDE Irvine32.inc

.data
	num1 DWORD 95
	num2 DWORD 31 
	num3 DWORD 240
	num4 DWORD  125

.code
main proc
	mov eax, num1
	sub eax, num2
	add eax, num3
	sub eax, num4

	
	call WriteDec    

main ENDP
END main


