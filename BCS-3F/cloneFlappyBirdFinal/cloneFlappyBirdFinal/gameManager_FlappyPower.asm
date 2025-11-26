.686
.model flat, stdcall
option casemap:none
include Irvine32.inc

.data
; nothing needed

.code
PUBLIC gameManager_birdPhysics

gameManager_birdPhysics PROC velocity:REAL4, angle:REAL4, gravity:REAL4, flapPower:REAL4, isFlap:DWORD

    mov eax, isFlap
    cmp eax, 0
    jne DoFlap

ApplyGravity:
    ; velocity += gravity
    fld velocity     ; ST0 = velocity
    fadd gravity     ; ST0 = velocity + gravity
    jmp Done

DoFlap:
    fld flapPower    

Done:
    ret
gameManager_birdPhysics ENDP

END
