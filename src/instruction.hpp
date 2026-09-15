#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>

enum class Opcode : uint8_t{
    LDA = 0x0,
    ADD = 0x1,
    SUB = 0x2,
    OUT = 0xE,
    HLT = 0xF
};

struct Instruction{
    Opcode opcode;
    uint8_t operand;
};



#endif
