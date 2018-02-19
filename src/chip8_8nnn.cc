#include "chip8.h"
namespace chip8 {

/*
 * 8XY0: Set VX to VY
 * 8XY1: Set VX to VX | VY
 * 8XY2: Set VX to VX & VY
 * 8XY3: Set VX to VX ^ VY
 * 8XY4: Add VY to VX, set VF to 1 if there's a carry
 * 8XY5: Subtract VY from VX, set VF to 1 if there's no borrow
 * 8XY6: Shift VY right by 1 and copy to VX, set VF to the erased bit
 * 8XY7: Set VX = VY - VX, set VF to 1 if there's no borrow
 * 8XYE: Shift VY left by 1 and copy to VX, set VF to the erased bit
 */
void Emulator::Op8NNN(unsigned short opcode) {
    int x = opcode & 0x0F00 >> 8;
    int y = opcode & 0x00F0 >> 4;
    switch(opcode & 0x000F) {
        case 0x0000:
            registers_[x] = registers_[y];
            break;
        case 0x0001:
            registers_[x] = registers_[x] | registers_[y];
            break;
        case 0x0002:
            registers_[x] = registers_[x] & registers_[y];
            break;
        case 0x0003:
            registers_[x] = registers_[x] ^ registers_[y];
            break;
        case 0x0004:
            if(registers_[x] > 0xFF - registers_[y]) {
                registers_[0xF] = 1;
            }
            registers_[x] = registers_[x] + registers_[y];
            break;
        case 0x0005:
            if(registers_[x] > registers_[y]) {
                registers_[0xF] = 1;
            }
            else {
                registers_[0xF] = 0;
            }
            registers_[x] = registers_[x] - registers_[y];
            break;
        case 0x0006:
            registers_[0xF] = registers_[y] & 0x0001;
            registers_[x] = registers_[y] >> 1;
            break;
        case 0x0007:
            if(registers_[x] > registers_[y]) {
                registers_[0xF] = 1;
            }
            else {
                registers_[0xF] = 0;
            }
            registers_[x] = registers_[x] - registers_[y];
            break;
        case 0x000E:
            registers_[0xF] = (registers_[y] & 0x8000) >> 31;
            registers_[x] = registers_[y] << 1;
            break;
        default:
            // Handle unknown opcode
            break;
    }
    pc_ += 2;
}

}