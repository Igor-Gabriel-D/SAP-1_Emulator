#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"

int main(){
    Memory mem;
    mem.write(0x00, 0x01);
    std::cout << static_cast<int>(mem.read(0x00)) << std::endl;

    CPU cpu;
    std::cout << "CPU initialized" << std::endl;

    std::cout << "Hello SAP-1" << std::endl;
    return 0;
}
