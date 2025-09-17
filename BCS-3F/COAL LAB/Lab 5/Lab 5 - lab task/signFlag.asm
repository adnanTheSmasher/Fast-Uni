include irvine32.inc
.data
.code
Main2 Proc
mov AL,15
sub AL,97
call dumpregs
exit
Main2 ENDP
END main2