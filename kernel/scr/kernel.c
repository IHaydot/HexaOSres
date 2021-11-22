void start(){
    char* vga_buffer = (char*) 0xb8000;
    *vga_buffer = 'x';
}