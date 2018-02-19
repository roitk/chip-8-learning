#include "chip8.h"
namespace chip8 {

/*
 * 2NNN: Call subroutine at NNN
 */
void Emulator::Op2NNN(unsigned short opcode) {
    stack_[sp_] = pc_;
    ++sp_;
    pc_ = opcode & 0x0FFF;
}

}