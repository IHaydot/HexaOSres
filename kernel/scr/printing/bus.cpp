#pragma once
#include "../sources.h"
void outb(uint16_t port, uint8_t value){
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}
uint8_t inb(uint16_t port){
    uint8_t RETvalue;
    asm volatile ("inb %1, %0" : "=a"(RETvalue) : "Nd"(port));
    return RETvalue;
}
