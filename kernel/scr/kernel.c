#include <stdint.h>
void start(){
    set_cursor_position(get_pos_from_coords(0, 1));
    println("Hello world!");
    while(1 == 1){

    }
    __asm__("hlt");
}