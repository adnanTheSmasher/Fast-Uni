TITLE "Adnan Hatim 24K-0656"
INCLUDE Irvine32.inc
.data
	arrayB BYTE 25, 45, 65
	arrayW WORD 155, 185, 225
	arrayD DWORD 645, 690, 735

	SUM1 DWORD ?
	SUM2 DWORD ?
	SUM3 DWORD ?

.code
main4 proc
	movzx AX, BYTE PTR arrayB[0]
	mov BX, arrayW[0]
	add AX, BX
	movzx EAX, AX
	add EAX, arrayD[0]
	mov SUM1, EAX

	movzx AX, BYTE PTR arrayB[1]
	mov BX, arrayW[2]
	add AX, BX
	movzx EAX, AX
	add EAX, arrayD[4]
	mov SUM2, EAX

	movzx AX, BYTE PTR arrayB[2]
	mov BX, arrayW[4]
	add AX, BX
	movzx EAX, AX
	add EAX, arrayD[8]
	mov SUM3, EAX

	
	mov EAX, SUM1
	call WriteDec
	call Crlf
	
	mov EAX, SUM2
	call WriteDec
	call Crlf
	
	mov EAX, SUM3
	call WriteDec
	call Crlf
	
	exit
main4 ENDP
END main4