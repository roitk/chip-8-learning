#include "chip8.h"
namespace chip8 {

/*
 * 1NNN: Jump to address NNN
 */
void Emulator::Op1NNN(unsigned short opcode) {
    pc_ = opcode_ & 0x0FFF;
}

}