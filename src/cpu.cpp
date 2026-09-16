#include "cpu.hpp"

CPU::CPU(){
    reset();
}


void CPU::reset(){
    PC  = 0x00;
    MAR = 0x00;
    IR  = 0x00;
    A   = 0x00;
    B   = 0x00;
    OUT = 0x00;

    cycle_state = CycleState::T1;

    current_instruction = {};
}

void CPU::cycle(Memory& memory){

    switch(cycle_state){
    case CycleState::T1:
	    MAR = PC;
	    cycle_state = CycleState::T2;
	    break;
	case CycleState::T2:
	    IR = memory.read(MAR);
	    PC++;
        current_instruction = decode();
	    cycle_state = CycleState::T3;
	    break;
    case CycleState::T3:
        execute(current_instruction, memory);

        cycle_state = CycleState::T1;
        break;
    }
}

Instruction CPU::decode() const{
    Instruction instruction;

    instruction.opcode = static_cast<Opcode>( (IR >> 4) & 0x0F );
    instruction.operand = IR & 0x0F;

    return instruction;
}

void CPU::execute(const Instruction& instruction, Memory& memory)
{
    switch (instruction.opcode)
    {
        case Opcode::LDA:
            A = memory.read(instruction.operand);
            break;
        case Opcode::ADD:
            B = memory.read(instruction.operand);
            A = alu.add(A, B);
            break;
        case Opcode::SUB:
            B = memory.read(instruction.operand);
            A = alu.sub(A, B);  
            break;
        case Opcode::OUT:
            OUT = A;
            break;
    }
}

uint8_t CPU::get_pc()  const { return PC; }
uint8_t CPU::get_mar() const { return MAR; }
uint8_t CPU::get_ir()  const { return IR; }
uint8_t CPU::get_a()   const { return A; }
uint8_t CPU::get_b()   const { return B; }
uint8_t CPU::get_out() const { return OUT; }

void CPU::set_a(uint8_t value){ A = value; }
