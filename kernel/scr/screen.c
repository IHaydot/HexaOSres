void print_char(char char){
    
}

void print(){
    char* vga_buffer = (char*) 0xb8000;
    *vga_buffer = 'X';
}