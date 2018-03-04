#include "chip8.h"
namespace chip8 {

/*
 * 0x0NNN: Call RCA 1802 program at address NNN
 * 0x00E0: Clear screen
 * 0x00EE: Return from a subroutine
 */
void Emulator::Op0NNN(unsigned short opcode) {
    switch(opcode) {
        case 0x00E0:
            for(int i = 0; i < kScreenSize; ++i) {
                screen_[i] = 0;
            }
            pc_ += 2;
            break;
        case 0x00EE:
            pc_ = stack_[sp_];
            --sp_;
            break;
        default:
            // TODO: Unknown opcode
            pc_ += 2;
            break;
    }
}

}