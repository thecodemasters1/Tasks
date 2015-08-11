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
str1 db "one", 0 ;Stores first string here
str2 db "two", 0 ;Stores second string here

Strcmp: ;Get as parameter 2 strings and compare them, return 1 if equal, otherwise return 0 (return value is stored in eax)
  PUSH ebp ;Start function here cdecl format
  MOV ebp, esp
  PUSH esi
  PUSH edi 

  Check: ;"WHILE LOOP" label, ompare the string, char at a time
    MOV al, byte ptr [esi] ;Get current char from str1
    MOV bl, byte ptr [edi] ;Get current char from str2
    CMP al, bl ;Compare the chars
    JNZ break_false ;If not equal, go to break_false label
    CMP al, 0 ;compare al to 0, if 0 then they are both 0 (al, bl) and the strings are equal
    JZ break_true ;if is indeed 0, strings are equal, go to break_true
    INC esi ;move esi (pointer to char in str1) to the next char
    INC edi ;move edi (pointer to char in str2) to the next char
   JMP Check ;Loop

  break_true: ;if strings are equal
    MOV eax, 1 ;Set eax as 1
    JMP endf ;go to the end of the function
  break_false: ;if strings are different
  MOV eax, 0 ;Set eax as 0, continue to the end of the function

  endf: ;function end start here
  
  POP edi
  POP esi
  POP ebp
  RET

Main: ;Take the 2 stored string and compare them, print 0 if same, otherwise their difference
  MOV esi, offset [str1] ;Parameter 1
  MOV edi, offset [str2] ;Parameter 2
  CALL Strcmp ;Call the string compare function, compaare string pointed from esi (str1) and edi (str2) return 1 if equal, otherwise return 1 (return val in eax)
  print str$(eax) ;Print the result
exit

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end start                       ; Tell MASM where the program ends
