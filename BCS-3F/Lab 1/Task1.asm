COMMENT!
INCLUDE Irvine32.inc
.data
	num1 DWORD 25
	num2 DWORD 47 
	num3 DWORD 88
	num4 DWORD  64
	num5 DWORD 120h
	num6 DWORD 27o
	subractor DWORD 0Ah

.code
main proc
	mov eax, num1
	add eax, num2
	add eax, num3
	add eax, num4
	add eax, num5
	add eax, num6

	sub eax, subractor
	
	call WriteDec    

!
main ENDP
END main


