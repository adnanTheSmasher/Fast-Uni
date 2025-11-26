.386
.model flat, stdcall
.stack 4096
include Irvine32.inc

.code

PUBLIC gameManager_getRandom
PUBLIC gameManager_randomize

gameManager_randomize PROC
    call Randomize
    ret
gameManager_randomize ENDP

; int gameManager_getRandom(int maxValue)
gameManager_getRandom PROC maxValue:DWORD
    mov eax, maxValue
    call RandomRange      ; random number 0..maxValue-1
    ret
gameManager_getRandom ENDP

END
