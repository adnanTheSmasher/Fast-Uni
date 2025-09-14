TITLE "24K-0656 Adnan"  
INCLUDE Irvine32.inc  
.data  
A DWORD 0ff10h  
B DWORD 0E108h  
.code  
main proc  
mov EAX, A  
XCHG EAX, B  
mov A, EAX  
exit  
main ENDP  
END main  