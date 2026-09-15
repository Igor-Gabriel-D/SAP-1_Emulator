#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"

int main(){
    CPU cpu;
    Memory memory;
    memory.write(0x00, 0x42);

    cpu.cycle(memory); // T1
    cpu.cycle(memory); // T2

    Instruction instruction = cpu.decode();

    std::cout << "Opcode  = 0x"
          << std::hex
          << static_cast<int>(instruction.opcode)
          << '\n';

    std::cout << "Operand = 0x"
          << std::hex
          << static_cast<int>(instruction.operand)
          << '\n';
    return 0;
}
