#include "chip8.h"
namespace chip8 {

/*
 * 6XNN: Set VX to NN
 */
void Emulator::Op6NNN(unsigned short opcode) {
    int x = opcode & 0x0F00 >> 8;
    unsigned char nn = static_cast<unsigned char>(opcode & 0x00FF);
    registers_[x] = nn;
    pc_ += 2;
}

}