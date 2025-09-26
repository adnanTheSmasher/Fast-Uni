TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc
.data
	array1 WORD 45, 32, 71, 44, 92 
	array2 WORD 5 DUP(?)
	spaceStr BYTE " "
.code
main3 proc
	mov esi, OFFSET array1
	mov ecx, 5
	printArray:
		movzx EAX, WORD PTR [esi]
		call WriteDec
		mov EDX, OFFSET spaceStr
		call WriteString
		add esi, 2
		loop printArray
	call Crlf

	mov esi, OFFSET array1
	mov edi, OFFSET array2

	mov AX, [esi + 2]
	mov  [edi],  AX ; 32

	mov AX, [esi + 6]
	mov  [edi+2],  AX;  44

	mov AX, [esi]
	mov  [edi+4],  AX ; 45

	mov AX, [esi + 4]
	mov  [edi+6],  AX ; 71

	mov AX, [esi + 8]
	mov  [edi+8],  AX ; 92

	mov esi, OFFSET array2;
	mov ecx, 5
	printArray2:
		movzx EAX, WORD PTR [esi]
		call WriteDec
		mov EDX, OFFSET spaceStr
		call WriteString
		add esi, 2
		loop printArray2


	exit
main3 ENDP
END main3