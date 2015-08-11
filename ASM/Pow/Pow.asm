; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

;                 Build this with the "Project" menu using
;                       "Console Assemble and Link"

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    .486                                    ; create 32 bit code
    .model flat, stdcall                    ; 32 bit memory model
    option casemap :none                    ; case sensitive
 
    include \masm32\include\windows.inc     ; always first
    include \masm32\macros\macros.asm       ; MASM support macros

  ; -----------------------------------------------------------------
  ; include files that have MASM format prototypes for function calls
  ; -----------------------------------------------------------------
    include \masm32\include\masm32.inc
    include \masm32\include\gdi32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc

  ; ------------------------------------------------
  ; Library files that have definitions for function
  ; exports and tested reliable prebuilt code.
  ; ------------------------------------------------
    includelib \masm32\lib\masm32.lib
    includelib \masm32\lib\gdi32.lib
    includelib \masm32\lib\user32.lib
    includelib \masm32\lib\kernel32.lib

    .code                       ; Tell MASM where the code starts

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

start:                          ; The CODE entry point to the program
JMP Main ;Skip function, start in the main code
Pow: ;Get 2 parameters: eax - BASE, ebx - POWER | return: eax <- eax^ebx
  PUSH ebp ;set the stack frame
  MOV ebp, esp
  PUSH ebx

  MOV eax, 1 ;Set eax to 1 (case Power is 0)
  MOV ecx, [ebp+12] ;Set the power in ecx to loop N times
  DoPow: ;Do the actual power, Multiplies the Base (eax) by itself N times (ebx) - Power
    MUL dword ptr [ebp+8] 
  LOOP DoPow

  print str$(eax) ;Print the result

  POP ebx ;End of function start here
  POP ebp 
  RET

Main: ;;Set to numbers in eax (base) and ebx (power) and print base^power (stored in eax)
  MOV eax, 2 ;Store Base in eax
  MOV ebx, 8 ;Store Power in ebx
  PUSH ebx ;BASE - Param 2
  PUSH eax ;Power - Param 1
  CALL Pow ;Call the power function, return: eax <- eax^ebx
  POP eax ;Clean parameter 1 from stack
  POP ebx ;Clean Parameter 2 from stack
exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
