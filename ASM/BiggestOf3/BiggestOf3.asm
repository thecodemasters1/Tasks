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
    MOV eax, 100 ;Number 1
    MOV ebx, 200 ;Number 2
    MOV ecx, 300 ;Number 3

	;Check which number is the biggest, store it in eax and print it

    CMP eax, ebx ;Compare eax to ebx
    JG eaBig ;If eax is greater, go to eaBig
    MOV eax, ebx ;If not, move ebx value to eax and then continue (moves to eaBig)
    eaBig: ;Check eax with ecx
      CMP eax, ecx ;Compare eax to ecx
      JG end_label ;If eax is bigger go to end_label and print
    MOV eax, ecx ;If not, move ecx value to eax and the continue (moves to end_label)
    end_label: ;Finish and print
      print str$(eax) ;Print biggest number
    exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
