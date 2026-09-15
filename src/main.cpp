#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"

int main(){
    Memory memory;
    CPU cpu;

    cpu.set_a(0x42);

    Instruction instruction;
    instruction.opcode = Opcode::OUT;
    instruction.operand = 0x0;

    cpu.execute(instruction, memory);

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
