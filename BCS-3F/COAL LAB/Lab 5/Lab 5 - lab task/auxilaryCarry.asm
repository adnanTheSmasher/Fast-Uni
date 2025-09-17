include irvine32.inc
.data
.code
Main3 Proc
mov AL,0Fh
sub AL,1
call dumpregs
exit
Main3 ENDP
END main3