#define VIDEO_ADRESS 0xb8000
#define VGA_COLOR 0x14
#define MAX_ROWS 25
#define MAX_COLS 80
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

#include <stdint.h>
#include <stdbool.h>
enum VGA_COLORS {
    VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

int init_terminal(int attribute_byte){
	int row = 0, col = 0, color = attribute_byte;
	unsigned char *vidmem = (unsigned char *) VIDEO_ADRESS;
	if(!attribute_byte){
		color = VGA_COLOR;
	}
	int offset;
	offset = get_screen_offset(row, col, offset);

	return offset;
}

int get_screen_offset(int row, int col, int offset){
	port_byte_out(REG_SCREEN_CTRL , 14);
	port_byte_out(REG_SCREEN_DATA , (unsigned char)( offset >> 8));
	port_byte_out(REG_SCREEN_CTRL , 15);
}

void println(const char *chr, char attribute_byte ,int offset){
    print_char(chr, strlen(chr), offset);
}
void print_char(const char *chr, int len, int offset){
	

}
int strlen(const char *chr){
	int len = 0;
	while(chr[len]){
		len++;
	}
	return len;
}
