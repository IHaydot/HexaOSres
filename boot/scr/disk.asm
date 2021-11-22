[bits 16]
init_disk:
    push dx
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13
    jc disk_error
    pop dx
    cmp dh, al
    jne sector_error
    ret
disk_error:
    mov bx, disk_message
    call print_strx16
    jmp $
disk_message: db 'Failed to read disk...', 0
sector_error: 
    mov bx, sector_message
    call print_strx16
    jmp $
sector_message: db 'Failed to read sector...', 0