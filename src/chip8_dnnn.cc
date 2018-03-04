#include "chip8.h"
namespace chip8 {

/*
 * DXYN: Draw N lines to X, Y
 */
void Emulator::OpDNNN(unsigned short opcode) {
    int col_start = registers_[(opcode & 0x0F00) >> 8];
    int row_start = registers_[(opcode & 0x00F0) >> 4];
    int height = opcode & 0x000F;
    registers_[0xF] = 0;

    for(int row = 0; row < height; row++) {
        unsigned char sprite = memory_[index_ + row];
        for(int col = 0; col < 8; col++) {
            // Screen is 64x64
            int pixel = (row + row_start) * 64 + (col + col_start);
            // Select the current bit of the sprite
            unsigned char sprite_pixel = (sprite >> (8 - (col + 1))) & 0x1;

            // Set collision flag if a 1 is set to 0
            if(screen_[pixel] == 1 && !(sprite_pixel)) {
                registers_[0xF] = 1;
            }
            screen_[pixel] = sprite_pixel;
        }
    }

    draw_flag_ = true;
    pc_ += 2;
}

}