TITLE "Adnan Hatim 24K-0656"
INCLUDE Irvine32.inc

.data
    msg  BYTE "Enter your student ID: ", 0
    fullAns BYTE "Your Student Id is ", 0
    ans BYTE 30 DUP(?) 

.code
main PROC

    mov edx, OFFSET msg
    call WriteString

 
    mov edx, OFFSET ans
    mov ecx, 30
    call ReadString

    call CrLf


    mov edx, OFFSET fullAns
    call WriteString

  
    mov edx, OFFSET ans
    call WriteString

    exit
main ENDP
END main

