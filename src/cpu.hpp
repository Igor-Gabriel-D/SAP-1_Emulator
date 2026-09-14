#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>

class CPU{
private:
    uint8_t PC;
    uint8_t MAR;
    uint8_t IR;
    uint8_t A;
    uint8_t B;
    uint8_t OUT;
public:
    CPU();

    void reset();
};

#endif
