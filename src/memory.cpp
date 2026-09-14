#include "memory.hpp"

uint8_t Memory::read(uint8_t address){
    
    if(address > 0x0f) throw std::out_of_range("Invalid memory address");

    return data[address];
}

void Memory::write(uint8_t address, uint8_t value){
    if(address > 0x0f) throw std::out_of_range("Invalid memory address");
    data[address] = value;
}
