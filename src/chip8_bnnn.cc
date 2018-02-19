#include "chip8.h"
namespace chip8 {

/*
 * BNNN: Jump to NNN + V0
 */
void Emulator::OpBNNN(unsigned short opcode) {
    pc_ = (opcode & 0x0FFF) + registers_[0];
}

}