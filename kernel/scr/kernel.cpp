#pragma region reprocessor
#pragma once
#ifdef __Linux__
    #error "Use a cross compiler"
#endif

#include "printing/writer.h"

#pragma endregion
extern "C" void _main(){
    char* mem = (char*) 0xb8000;
    *mem = 'X';
    print();

    while(true){

    }
    asm("hlt");
}