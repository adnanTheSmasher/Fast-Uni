INCLUDE Irvine32.inc

.data
	msg1 BYTE "How many students: ", 0
	msg2 BYTE "Enter Marks of Student ",0
	msg3 BYTE " : ",0
	msg4 BYTE "number Of student Pass: ", 0
	msg5 BYTE "number Of student Fai: ",0

	marks WORD 100 DUP(?)
	countPass DWord ?
	countFail DWord ?
	student Dword ?


.code
main PROC
	mov EDX, offset msg1
	call WriteString
	call ReadInt
	
	mov student, eax

	mov ecx, student
	mov esi, offset marks
	mov ebx, 0

loop1:
	mov eax, ebx
	call crlf
	mov edx, offset msg2
	call WriteString
	call WriteDec
	mov edx, offset msg3
	call WriteString

	call ReadInt

	mov [esi], eax
	add esi, 2
	INC ebx
	loop loop1
	
	call checkForPass

	mov EDX, offset msg4
	call WriteString
	mov EAX, countPass
	call WriteDec
	call Crlf
	mov EDX, offset msg5
	call WriteString
	mov EAX, countFail
	call WriteDec


checkForPass PROC
	mov ecx, student
	mov esi, offset marks

checker:
	mov eax, [esi]
	cmp eax, 50
	jl failCount
	inc CountPass
	jmp cont

failCount:
	inc countFail

cont:
	add esi, 2
	loop checker
	ret

CheckForPass ENDP
exit
main ENDP
END main

