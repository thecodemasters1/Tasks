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

Fibo: ;Get number N as a parameter and return the value of the N'th fibonacci member in eax (recursively)
  PUSH ebp ;Start function here cdecl format
  MOV ebp, esp
  PUSH ebx

  CMP dword ptr [ebp+8], 2 ;Check the base case, if param<=2, then add 1 to eax and 
  JBE Base_Case

  MOV ebx, [ebp+8] ;Get the function's parameter to work with it

  DEC ebx ;Send N-1 and calculate it to sum (recursively)
  PUSH ebx ;Send parameter to function
  CALL Fibo ;Recursive call for N-1
  MOV ecx, eax ;Store the value of the last call (thus there is no need to reset eax at the begining)
  POP ebx ;Clean parameter from stack

  PUSH ecx ;Store current value from last call in the stack, because the recursion is going to change it
  DEC ebx ;Send N-2 and calculate it to sum (recusively)
  PUSH ebx ;Send parameter to function
  CALL Fibo ;Recursive call for N-2
  POP ebx ;Clean parameter from stack
  POP ecx ;Get back the original value of ecx (ecx from calls already in eax)

  ADD eax, ecx ;Move current value of ecx to eax, where the solution will be stored

  JMP skip_to_end ;Go to the function's end, skip the base case

  Base_Case: ;Base case, N <= 2
    MOV eax, 1 ;set eax as 1

  skip_to_end:
  
  POP ebx ;function end start here
  POP ebp
  RET

Main: ;Get a number, marked as N, and return and Nth fibonacci number 
  MOV ebx, 5 ;Store N in ebx
  PUSH ebx ;First parameter - N
  CALL Fibo ;Call the Fibonacci recursive function, passes ebx (N), return the Nth Fibonacci number in eax
  print str$(eax) ;Print the result
  POP ebx; clean parameter from stack
exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
