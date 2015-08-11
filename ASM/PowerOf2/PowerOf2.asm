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
    MOV eax, 9 ;Set start value to check if is a power of 2
    Check2: ;Loop label
      SHR eax, 1 ;Divide number by 2 (Case number is a power of 2), otherwise just remove the last bit
      CMP eax, 2 ;Compare current value to 2
      JZ case_Pow ;If value is 2, the number is a a power of 2 and therfore get out of the loop
      CMP eax, 2 ;Compare again to 2
      JB case_noPow ;If the vlaue is smaller than 2, then the original number was not a power of two, get out of the loop
      JMP Check2 ;In anyothere case (Value > 2) keep looping
    case_Pow: ;If power of 2
      MOV eax, 0 ;Set eax value to 0
      JMP end_prt ;Go to the end_prt label
    case_noPow: ;If not power of 2
      MOV eax, 1 ;Set eax value to 1
      JMP end_prt ;Go th the end prt label, Not a neccessary label jump, just to make it look more in a struct
    end_prt: ;end label, print the value of eax
      print str$(eax) ;print eax value
    exit
      

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
