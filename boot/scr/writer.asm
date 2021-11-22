[bits 16]
print_strx16:
    pusha
char_loop:
    mov al, [bx]
    cmp al, 0
    jne print_char
    popa
    ret
print_char:
    mov ah, 0x0e
    int 0x10
    add bx, 1
    jmp char_loop
[bits 32]
VIDEO_MEMORY equ 0xb8000
COLOR equ 0x0f
print_strx32:
    pusha
    mov edx, VIDEO_MEMORY
char_loopx32:
    mov al, [ebx]
    mov ah, COLOR
    cmp al, 0
    je done_print
    mov [edx], ax
    add ebx, 1
    add edx, 2
    jmp char_loopx32
done_print:
    popa
    ret
