#include "chip8.h"
#include <random>
namespace chip8 {

/*
 * CXKK: Generate a random number from 0-255, AND it with KK, then store in VX
 */
void Emulator::OpCNNN(unsigned short opcode) {
    unsigned char kk = opcode & 0xFF;
    std::uniform_int_distribution<int> dist(0, 255);
    unsigned char rand_num = dist(rng);
    int x = opcode & 0x0F00 >> 8;
    registers_[x] = rand_num & kk;
    pc_ += 2;
}

}