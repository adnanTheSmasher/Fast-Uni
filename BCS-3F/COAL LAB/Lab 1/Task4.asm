INCLUDE Irvine32.inc
.data
	num1 DWORD 11010110b
	num2 DWORD 9C4h
	num3 DWORD 220
	num4 DWORD  18
	num5 DWORD 1011110b
	num6 DWORD 0Dh
	num7 DWORD 12

.code
main proc
	mov eax, num1
	sub eax, num2
	add eax, num3
	add eax, num4
	add eax, num5
	sub eax, num6
	add eax, num7
	
	call WriteInt    

main ENDP
END main

