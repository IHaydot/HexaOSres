#pragma once
#define VIDEO_MEMORY_START (uint8_t*)0xb8000
#define VGA_COLOR 0x0f
#include "../sources.h"
#include "bus.h"
uint16_t cursor_pos;
void SetCursorPosition(uint16_t pos){
    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t)(pos & 0xff));
    outb(0x3d4, 0x0e);
    outb(0x3d5, (uint8_t)((pos >> 8) & 0xff));

    cursor_pos = pos;
}
int strlen(const char* str){

}
void print_str(const char* str){
    
}