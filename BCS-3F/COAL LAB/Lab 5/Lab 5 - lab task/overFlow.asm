include irvine32.inc
.data
.code
Main4 Proc
mov AL,72h
add AL,0Eh
call dumpregs
exit
Main4 ENDP
END main4