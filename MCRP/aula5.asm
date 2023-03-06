; multi-segment executable file template.

data segment   
    Size dw 10
    NumElemTab db 3
    Tabela1 db "Bola      ","Salto       ","Futebol   "
    Tabela2 db "Bola      ","Golo        ","Futebol   "
    True db "True", 0
    False db "False", 0
    Enter db 0dh, 0ah, 0
    Resultado db 3 dup(?)

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
                 
    cld
    lea si, Tabela1
    lea di, Tabela2
    lea bx, Resultado
    mov ax, Size
    
    mov dl, NumElemTab
    
    call Comp
    call PrintRes
    
    mov ax, 4c00h ; exit to operating system.
    int 21h  
    
    Comp proc
        push dx
        push cx
        push bx 
        xor dh, dh   
        Cicle:
            mov cx, ax
            repe cmpsb
            jnz Dif
            mov [bx], 1  
            jmp Verif
        Dif:
            add si, cx
            add di, cx
            mov [bx], 0  
            
        Verif:
            inc bx
            inc dh
            cmp dh, dl
            jne Cicle
        pop bx
        pop cx
        pop dx
        ret
    Comp endp
    
    PrintRes proc
        push bx
        push si
        push dx
        
        NextRes:
        cmp [bx], 1
        jne NotTrue
        lea si, True
        jmp PrintTF
        
        NotTrue:
            lea si, False
            
        PrintTF:
            call PrintStr
            lea si, enter
            call PrintStr
            inc bx
            dec dl
            cmp dl, 0
            je EndPrintRes
            jmp NextRes
        
        EndPrintRes:
            pop dx
            pop si
            pop bx
            ret
    PrintRes endp
    
    PrintStr proc
        push ax
        Print:
        mov al, byte ptr [si]
        or al, al
        jz EndPrint
        call PrintChar
        inc si
        jmp Print
        
        EndPrint:
        pop ax
        ret
    PrintStr endp
    
    PrintChar proc
        push ax
        push dx
        mov ah, 02h
        mov dl, al
        int 21h
        pop dx
        pop ax
        ret
    PrintChar endp
      
ends

end start ; set entry point and stop the assembler.
