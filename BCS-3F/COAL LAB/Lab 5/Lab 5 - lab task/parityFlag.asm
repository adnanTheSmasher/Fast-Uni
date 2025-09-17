include irvine32.inc
.data
.code
Main Proc
mov AX,26
add AX,1
call dumpregs
exit
Main ENDP
END main