[bits 16]
printx16:
    pusha
char_loopx16:
    mov al, [bx]
    cmp al, 0
    jne print_char
    popa
    ret
print_char:
    mov ah, 0x0e
    int 0x10
    add bx, 1
    jmp char_loopx16