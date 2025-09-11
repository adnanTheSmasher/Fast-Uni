INCLUDE Irvine32.inc
.data
	num1 DWORD 101110b
	num2 DWORD 50Ah 
	num3 DWORD  67d
	num4 DWORD 1010001b
	num5 DWORD 0Fh

.code
main proc
	mov eax, num1
	add eax, num2
	add eax, num3
	add eax, num4
	add eax, num5
	
	call WriteDec    

main ENDP
END main


