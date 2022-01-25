[bits 32]
[extern _main]
mov [0xb8000], byte 'H'
call _main
jmp $
times 2048-($-$$) db 0