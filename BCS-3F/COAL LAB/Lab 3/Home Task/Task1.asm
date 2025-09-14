TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
    a DWORD 10h
    b DWORD 12h
    c DWORD 20h
    d DWORD 25h

.code
main PROC
   
    mov EAX, [a]
    add EAX, [b]

    sub EAX,  [a]
    add EAX,  [b]

    add EAX,  [c]

    add EAX,  [d]
   
    xchg EAX, EBX      

    exit
main ENDP
END main
