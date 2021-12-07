#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
int index = 0;
uint16_t cursor_pos;
uint16_t* VIDEO_MEMORY = (uint16_t*) 0xb8000;
 
uint16_t strlenm(const char* str){
	size_t len = 0;
	while(str[len]){
		len++;
	}
	return len;
}

/*
 *This function prints a line to the screen
*/
void println(const char* str){
	print_str(str, strlenm(str));
}

void print_str(const char* str, uint16_t len){
	for(int i; i < len; i++){
		print_char(str[i]);
	}
}

void print_char(char c){
	if(c == '\n'){
		new_line();
	}
	if(c == '\c'){
		clear_screen();
	}
	else{
		print_byte(c);
	}
}

void print_byte(char c){
	VIDEO_MEMORY[cursor_pos] = c;
}

void set_cursor_position(uint16_t pos){
	POut(0x3D4, 0x0F);
	POut(0x3D5, (unsigned char)(pos & 0xff));
	POut(0x3D4, 0x0e);
	POut(0x3D5, (unsigned char)((pos >> 8) & 0xff));

	cursor_pos = pos;
}

uint16_t get_pos_from_coords(unsigned char x, unsigned char y){
	return y * VGA_WIDTH + x;
}

void clear_screen(){
	for(int i = 0; i < 9999; i++){
		VIDEO_MEMORY[i] = ' ';
	}
}

void new_line(){
	//TODO
}


