#include "chip8.h"
namespace chip8 {

/*
 * FX07: Set VX to the value of the delay timer
 * FX0A: Wait for key press and store value in VX
 * FX15: Set delay timer to VX
 * FX18: Set sound timer to VX
 * FX1E: Add VX to I
 * FX29: Set I to location of the sprite for the character in VX ???
 * FX33: Store binary-coded decimal representation of VX ???
 * FX55: Store V0-VX in memory location starting at address I. I++ for each value written
 * FX65: Fill V0-VX with values starting at I. I++ for each value written
 */
void Emulator::OpFNNN(unsigned short opcode) {
    unsigned short subcode = opcode & 0x00FF;
    int x = (opcode & 0x0F00 >> 8);
    switch(subcode) {
        case 0x0007: {
            registers_[x] = delay_timer_;
            break;
        }
        case 0x000A: {
            // Handle key press
            char c;
            std::cin.get(c);
            while(keypad_mapping_.find(c) == keypad_mapping_.end()) {
                std::cin.get(c);
            }
            // Convert between key and value
            registers_[x] = keypad_mapping_[c];
            break;
        }
        case 0x0015: {
            delay_timer_ = registers_[x];
            break;
        }
        case 0x0018: {
            sound_timer_ = registers_[x];
            break;
        }
        case 0x001E: {
            index_ += registers_[x];
            break;
        }
        case 0x0029: {
            // The register will contain a single hexadecimal digit
            // Convert this to the digit's font location in memory

            // Fonts are stored starting at 0x50 == 80, and each is 
            // 8 wide and 5 high, so 40 bits each
            index_ = 0x80 + (40 * registers_[x]);
            break;
        }
        case 0x0033: {
            int value = registers_[x];
            // Ordinarily we'd have to mod by 100 to get the lower 3 digits, 
            // but the max value of a register is 255, so it's already < 1000
            memory_[index_] = value / 100;
            value = value % 100;
            memory_[index_ + 1] = value / 10;
            value = value % 10;
            memory_[index_ + 2] = value;
            break;
        }
        case 0x0055: {
            for(int i = 0; i <= x; i++) {
                memory_[index_] = registers_[i];
                index_++;
            }
            break;
        }
        case 0x0065: {
            for(int i = 0; i <= x; i++) {
                registers_[i] = memory_[index_];
                index_++;
            }
            break;
        }
        default: {
            // Unknown opcode
            break;
        }
    }
    pc_ += 2;
}

}