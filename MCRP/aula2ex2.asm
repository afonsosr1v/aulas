; multi-segment executable file template.

data segment 
    
    num1 dw 200
    num2 dw 60
    res dd ?
    
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
    
    
    mov ax, 0
    mov bx, num1
    mov cx, num2 
    mov dx, 0
    call multi
    mov res[0], ax
    mov res[2], dx
    jmp fim
      
    fim:  
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends         

    multi PROC
    cmp bx, num2
    jnb ciclo
    mov bx, num2
    mov cx, num1
    cmp cx, 0
    jne endsoma
    
    ciclo:
    call soma
    dec cx
    cmp cx, 0
    jne ciclo
    RET
    multi endp
    
    soma PROC
    add ax, bx
    jnc endsoma
    inc dx
    
    endsoma:
    RET
    
    soma endp
ends

end start ; set entry point and stop the assembler.
