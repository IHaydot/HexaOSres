#pragma once
void print(){
    char* mem = (char*) 0xb8000;
    *mem = 'C';
}