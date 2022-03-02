[org 0x7c00]
[bits 16]
mov [BOOT_DRIVE], dl
mov bp, 0x8000
mov sp, bp
mov bx, booting1
call printx16
jmp $
booting1: db 'Booting 1st stage...', 0
%include "boot/sect1/writer.asm"
times 510-($-$$) db 0
dw 0xaa55
