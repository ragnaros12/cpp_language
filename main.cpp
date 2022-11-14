#include <iostream>
#include "memory/Memory.h"
#include "defines/instructions.cpp"


int main() {
    Memory::init();

    auto* iConst = new IConst();
    auto* iLoad = new ILoad();


    int a = 0;
    byte* a1 = (byte*)&a;

    int b = 5;
    byte* b1 = (byte*)&b;

    iConst->run(b1, a1);
    iConst->run(b1, a1);

    iLoad->run(a1, a1);
    iLoad->run(a1, a1);


    Memory::read_all_stack();
    std::cout << "sosi" << std::endl;
    Memory::read_all_heap();
}