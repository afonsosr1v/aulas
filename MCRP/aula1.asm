; multi-segment executable file template.

data segment
    array db 1,2,3,4,5,86,160,8,109,8,7,6,5,23,100   
    elements EQU 100  
    Res db ?
    
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax
              
    mov bx, 0
  JPARRAY:          
    mov al, array[bx]
    mov cx, bx
  INCBX:
    add bx, 1 
    cmp bx, elements
    jg FIM 
    cmp al, array[bx]
    jb JPARRAY
    jae  INCBX
    
    
  FIM:
    mov Res, cl 
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
