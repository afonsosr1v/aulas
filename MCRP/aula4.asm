; multi-segment executable file template.

data segment    
    op1 db ?
    op2 db ?
    res dw ?
    simb db ?
    enter db 0dh, 0ah, 0
    bv db "Bem vindo a nossa calculadora!", 0
    oper db "Indique o tipo de operacao: ", 0
    prim db "Introduza o primeiro operando: ", 0
    seg db "Introduza o segundo operando: ", 0
    res1 db "O resultado de ", 0
    res2 db " e: ", 0
    error1 db "Operando ", 0
    error2 db " invalido", 0
    errorOP db "Operator invalido", 0
    obg db "Obrigado.", 0

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
    
    ;Bem vindo
    mov si, offset bv
    call PrintStr
    mov si, offset enter
    call PrintStr
    
    ;Ler o operador
    RepSimb:
    mov si, offset oper
    call PrintStr
    call LerSimb
    cmp al, -1
    jne SimbOK
    mov si, offset enter
    call PrintStr
    mov si, offset enter
    call PrintStr
    mov si, offset errorOP
    call PrintStr
    mov si, offset enter
    call PrintStr
    jmp RepSimb
    
    SimbOK:
    mov simb, al
    mov si, offset enter
    call Print   
    
    ;Ler os operandos
    RepOp1:
    mov si, offset prim
    call PrintStr
    mov cl, 1
    call LerOP
    cmp al, -1
    jne Op1OK
    call OpError
    jmp RepOp1
    
    Op1OK:
    mov op1, al
    mov si, offset enter
    call PrintStr
    
    RepOp2:
    mov si, offset seg
    call PrintStr
    mov cl, 2
    call LerOP
    cmp al, -1
    jne Op2OK
    call OpError
    jmp RepOp2
    
    Op2OK:
    mov op2, al
    mov si, offset enter
    call PrintStr
    cmp op1, -1
    je OpError
    cmp op2, -1
    je OpError
    
    ;operacao
    mov al, op1
    mov bl, op2
    mov ah, 0
    mov bh, 0
    cmp simb, 2bh
    jne NotSum
    call Sum
    jmp EndOp
    
    NotSum:
    cmp simb, 2dh
    jne NotSub
    call Subt
    jmp EndOp
    
    NotSub:
    cmp simb, 2ah
    jne NotMult
    call Multi
    jmp EndOp
    
    NotMult:
    call Divi
    
    EndOp:
    mov res, ax  
    
    ;escrever o resultado
    mov si, offset res1
    call PrintStr
    mov al, op1
    mov ah, 0
    call WriteUns
    mov al, simb
    call PrintChar
    mov al, op2
    mov ah, 0
    call WriteUns
    mov si, offset enter
    call PrintStr
    
    ;terminar o programa
    mov si, offset obg
    call PrintStr
    mov ax, 4c00h
    int 21h
    
    OpError proc
        mov si, offset enter
        call PrintStr
        mov si, offset error1
        call PrintStr
        add cl, 48
        mov al, cl
        call PrintChar
        mov si, offset error2
        call PrintStr
        mov si, offset enter
        call PrintStr
        ret
    OpError endp
    
    LerSimb proc
        mov ah, 1
        int 21h
        cmp al, 2bh
        je val
        cmp al, 2dh
        je val
        cmp al, 2ah
        je val
        cmp al, 5ch
        je val
        mov ax, -1
        val:
        ret
    LerSimb endp
    
    LerOP proc     
        mov dl, cl
        call ReadUns
        cmp dl, 1
        jne num2
        mov op1, al
        ret
        
        num2:
        mov op2, al
        ret
    LerOP endp
    
    ReadUns proc
        mov bl, 0
        mov ah, 0
        mov ch, 10
        
        ReadCicle:
        call ReadChar
        cmp al, 0dh
        je Fim
        cmp al, 30h
        jl Error
        cmp al, 39h
        jg Error
        sub al, 48
        mov cl, al
        mov al, bl
        mul ch
        jc Error
        mov bl, al
        mov al, cl
        add bl, al
        jnc ReadCicle
        
        Error:
        mov al, -1
        ret
        
        Fim:
        mov al, bl
        ret
    ReadUns endp
    
    WriteUns proc
        mov bx, 10
        mov cx, 0
        
        ScanCicle:
        mov dx, 0
        div bx
        push dx
        inc cx
        cmp ax, 0
        jne ScanCicle
        
        WriteCicle:
        pop ax
        add ax, 48
        call PrintChar
        dec cx
        cmp cx, 0
        jnz WriteCicle
        ret
    WriteUns endp
    
    PrintStr proc
        Print:
        mov al, byte ptr [si]
        or al, al
        jz EndPrint
        call PrintChar
        inc si
        jmp Print
        
        EndPrint:
        ret
    PrintStr endp
    
    PrintChar proc
        mov ah, 02h
        mov dl, al
        int 21h
        ret
    PrintChar endp
    
    Multi PROC
        cmp ax, bx
        jnl OK
        xchg ax, bx
        
        OK:
        mov cx, bx
        mov bx, ax
        
        MultiCicle:
        call Sum
        dec cx
        cmp cx, 1
        jne MultiCicle
        ret
    Multi endp
    
    Sum proc
        add ax, bx
        jnc endsoma
        inc dx
        
        endsoma:
        ret
    Sum endp
    
    Divi proc
        mov cx, -1
        
        ciclo:
        inc cx
        call Subt
        cmp ax, 0
        jge ciclo
        mov ax, cx
        ret
    Divi endp
    
    Subt proc
        sub ax, bx
        ret
    Subt endp
       
ends

end start ; set entry point and stop the assembler.
