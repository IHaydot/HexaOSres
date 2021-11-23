 #include "stdint.h"
 #if defined(__linux__)
    #error "No Linux allowed >:("
#endif
#if !defined(__i386__)
    #error "No non i386 allowed >:("
#endif

void Entrance(){
    char* _ = (char*) 0xb8000;
    int i = 0;
    *_ = 'X';
}