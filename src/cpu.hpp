#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include "memory.hpp"
#include "instruction.hpp"
#include "alu.hpp"

enum class CycleState{
    T1,
    T2,
    T3
};

class CPU{
private:
    uint8_t PC;
    uint8_t MAR;
    uint8_t IR;
    uint8_t A;
    uint8_t B;
    uint8_t OUT;

    CycleState cycle_state;

    Instruction current_instruction;

    ALU alu;
public:
    CPU();

    void reset();
    void cycle(Memory& memory);
    Instruction decode() const;
    void execute(const Instruction& instruction, Memory& memory );


    uint8_t get_pc()  const;
    uint8_t get_mar() const;
    uint8_t get_ir()  const;
    uint8_t get_a()   const;
    uint8_t get_b()   const;
    uint8_t get_out() const;

    void set_a(uint8_t value);
};


#endif
