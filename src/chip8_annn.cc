#include "chip8.h"
namespace chip8 {

/*
 * ANNN: Set index register to NNN
 */

void Emulator::OpANNN(unsigned short opcode) {
    index_ = opcode & 0x0FFF;
    pc_ = pc_ + 2;
}

}