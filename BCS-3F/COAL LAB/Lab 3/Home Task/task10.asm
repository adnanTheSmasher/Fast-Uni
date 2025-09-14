TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
    msg BYTE "COMPUTER ORGANIZATION & ASSEMBLY LANGUAGE LAB", 0

.code
main PROC
   mov EDX, OFFSET msg
   call WriteString

    exit
main ENDP
END main
