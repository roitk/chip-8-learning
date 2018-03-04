#include "chip8.h"
namespace chip8 {

/*
 * EX9E: Skip next instruction if key with value VX is pressed
 * EXA1: Skip next instruction if key with value VX is not pressed
 */
void Emulator::OpENNN(unsigned short opcode) {
    int key = (opcode & 0x0F00 >> 8);
    switch(opcode & 0x00FF) {
        case 0x009E:
            if(key_[registers_[key]]) {
                pc_ += 2;
            }
            pc_ += 2;
            break;
        case 0x00A1:
            if(!key_[registers_[key]]) {
                pc_ += 2;
            }
            pc_ += 2;
            break;
        default:
            // Unknown opcode
            break;
    }
}

}