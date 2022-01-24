[bits 32]
[extern _main]
call _main
mov [0xb8000], byte 'H'
jmp $
times 16384-($-$$) db 0