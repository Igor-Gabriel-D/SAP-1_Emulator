#include "memory.hpp"

uint8_t Memory::read(uint8_t address){
    return data[address];
}

void Memory::write(uint8_t address, uint8_t value){
    data[address] = value;
}
