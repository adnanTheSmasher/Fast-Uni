include irvine32.inc
.data
.code
Main Proc
mov AX,0FFFFH
inc AX
call dumpregs
exit
Main ENDP
END main