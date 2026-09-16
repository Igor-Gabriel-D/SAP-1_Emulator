#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"

int main(){
    Memory memory;
    CPU cpu;

    //memory.write(0x00, 0x05); // LDA 5
    //memory.write(0x01, 0xE0); // OUT
    //memory.write(0x02, 0xF0); // HLT
    
    memory.write(0x00, 0x05); // LDA 5
    memory.write(0x01, 0x16); // ADD 6
    memory.write(0x02, 0xE0); // OUT
    memory.write(0x03, 0xF0); // HLT

    memory.write(0x05, 0x0A); // 10
    memory.write(0x06, 0x03); // 3

    while (cpu.is_running())
    {
        cpu.cycle(memory);
        //std::cout << "loop\n";
    }

    std::cout << "OUT = 0x"
              << std::hex
              << static_cast<int>(cpu.get_out())
              << '\n';

    
    return 0;
}
