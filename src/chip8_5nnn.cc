#include "chip8.h"
namespace chip8 {

/*
 * 5XY0: Skip next instruction if VX == VY
 */
void Emulator::Op5NNN(unsigned short opcode) {
    if((opcode & 0x000F) == 0) {
        int x = opcode & 0x0F00 >> 8;
        int y = opcode & 0x00F0 >> 4;
        if(registers_[x] == registers_[y]) {
            pc_ += 2;
        }
    }
    pc_ += 2;
}

}