TITLE "Adnan Hatim 24k-0656"
INCLUDE Irvine32.inc

.data

.code 
main PROC

	mov eax, 100
	mov ebx, 10
	cmp eax, ebx ;  cmp less than  
	call DumpRegs ; 

	mov ebx, 100
	cmp eax, ebx; cmp equal
	call DumpRegs 

	mov eax, 100
	mov ebx, 200
	cmp eax, ebx; cmp greter than 
	call DumpRegs
	exit

main ENDP
END main