 #if defined(__linux__)
    #error "No Linux allowed >:("
#endif
#if !defined(__i386__)
    #error "No non i386 allowed >:("
#endif

void Entrance(){
    print();
}