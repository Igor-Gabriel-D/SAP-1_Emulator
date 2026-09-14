#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>
#include <stdexcept>

class Memory{
private:
    uint8_t data[16]{};

public:
    uint8_t read(uint8_t address);
    void    write(uint8_t addres, uint8_t value);
};

#endif
