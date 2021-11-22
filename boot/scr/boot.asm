[bits 16]
[org 0x7c00]
KERNEL_OFFSET equ 0x1000
    mov ah, 0x00
    mov al, 0x03
    int 10h
    mov [BOOT_DRIVE], dl
    mov bp, 0x8000
    mov sp, bp
    mov bx, booting
    call print_strx16
    call load_kernel
    mov bx, success_disk
    call print_strx16
    mov ah, 0x00
    mov al, 0x03
    int 10h
    call switch_to_x32
    jmp $
BOOT_DRIVE: db 0
booting: db 'Booting...', 0
success_disk: db 'W', 0
load_kernel: 
    mov bx, KERNEL_OFFSET
    mov dh, 15
    mov dl, [BOOT_DRIVE]
    call init_disk
    ret
%include "C:\Users\home\Desktop\HexaOS\Csys\boot\scr\writer.asm"
%include "C:\Users\home\Desktop\HexaOS\Csys\boot\scr\disk.asm"
%include "C:\Users\home\Desktop\HexaOS\Csys\boot\scr\gdt.asm"
%include "C:\Users\home\Desktop\HexaOS\Csys\boot\scr\switch.asm"
[bits 32]
BEGIN_PM: 
    call KERNEL_OFFSET
    jmp $
x32: db 'Done', 0
times 510-($-$$) db 0
dw 0xaa55
times 256 dw 0xdada
times 256 dw 0xface
times 256 dw 0x0001
times 256 dw 0x0003
times 256 dw 0x0002