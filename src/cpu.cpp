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

uint8_t CPU::get_pc()  const { return PC; }
uint8_t CPU::get_mar() const { return MAR; }
uint8_t CPU::get_ir()  const { return IR; }
uint8_t CPU::get_a()   const { return A; }
uint8_t CPU::get_b()   const { return B; }
uint8_t CPU::get_out() const { return OUT; }
