include irvine32.inc
.data
.code
Main1 Proc
mov AL,0FH
add AL,0F1H
call dumpregs
exit
Main1 ENDP
END main1