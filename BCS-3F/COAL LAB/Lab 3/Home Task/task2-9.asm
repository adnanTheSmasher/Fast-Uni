TITLE "24K-0656 Adnan"
INCLUDE Irvine32.inc

.data
bArray BYTE 1, 2, 3, 4, 5, 6, 7, 8, 9, 10; TASK 2
svar BYTE 200 DUP("NUCES"); TASK 3
dArray DWORD 30 DUP(?); TASK 4
var WORD 10000,20000,30000; TASK 5
marks WORD 5 DUP(3 DUP(?)); TASK 6
dailySales SDWORD 2500, 10000, 45000, 12000, 15000, 45000, 7000; TASK 7

num1 DWORD 1000h
   num2 DWORD 2000h; TASK 8

   uArray WORD 20 DUP(5); TASK 9

.code
main PROC



exit
main ENDP
END main
