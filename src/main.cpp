#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"

int main(){
    Memory memory;
    CPU cpu;

    //memory.write(0x00, 0xE0);
    //cpu.set_a(0x42);
    memory.write(0x00, 0x05);
    memory.write(0x05, 0x37);

    cpu.cycle(memory); // T1
    cpu.cycle(memory); // T2
    cpu.cycle(memory); // T3
    
    std::cout << "A   = 0x"
          << std::hex
          << static_cast<int>(cpu.get_a())
          << '\n';

    std::cout << "OUT = 0x"
          << std::hex
          << static_cast<int>(cpu.get_out())
          << '\n';
    return 0;
}
