#define VIDEO_ADRESS 0xb8000
#define VGA_COLOR 0xf1
#define MAX_ROWS 25
#define MAX_COLS 80
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
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
int offset = 0;
int row = 0;
int col = 0;
uint16_t* vga_buffer = (uint16_t*) VIDEO_ADRESS;
/**
 * @brief Prints a character on screen, but does it by adding it straight to video memory. This means that it will always be written on cell 1 column 1.
 * 
 * @param byte 
 */
void printSTVM(char byte){
	vga_buffer = byte;
}
