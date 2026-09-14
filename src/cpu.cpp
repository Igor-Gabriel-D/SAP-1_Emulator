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
}
