#include "chip8.h"
namespace chip8 {

/*
 * 3XNN: Skip next instruction if registers_[x] == NN
 */
void Emulator::Op3NNN(unsigned short opcode) {
    int x = opcode & 0x0F00 >> 8;
    unsigned char nn = static_cast<unsigned char>(opcode & 0x00FF);
    if(registers_[x] == nn) {
        pc_ += 2;
    }
    pc_ += 2;
}

}