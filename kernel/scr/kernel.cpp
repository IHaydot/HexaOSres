#pragma region reprocessor
#pragma once
#ifdef __Linux__
    #error "Use a cross compiler"
#endif

#include "printing/writer.h"
#include "sources.h"

#define KERNEL_ENTRANCE_MESSAGE "Kernel successfully entered"
#pragma endregion
extern "C" void _main(){
    SetCursorPosition(1000);
    while(true){

    }
    asm("hlt");
}