#include "chip8.h"
namespace chip8 {

/*
 * 9XY0: Skip next instruction if VX != VY
 */
void Emulator::Op9NNN(unsigned short opcode) {
    if(opcode_ & 0x000F) {
        // Unknown opcode, last nibble should be 0
    }
    int x = opcode_ & 0x0F00 >> 8;
    int y = opcode_ & 0x00F0 >> 4;
    if(registers_[x] == registers_[y]) {
        pc_ += 2;
    }
    pc_ += 2;
}

}