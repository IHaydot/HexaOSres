#include <stdint.h>
void start(){
    int offset = init_terminal();
    println("hello", offset);
    while(1 == 1){

    }
    __asm__("hlt");
}