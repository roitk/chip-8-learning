#include "chip8.h"
namespace chip8 {

void Emulator::OpANNN(unsigned short opcode) {
    index_ = opcode_ & 0xF000;
    pc_ = pc_ + 2;
}

}