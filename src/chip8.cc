#include "chip8.h"
#include <iostream>

namespace chip8 {

void Emulator::Initialize() {
    pc_ = 0x200;
    opcode_ = 0;
    index_ = 0;
    pc_ = 0;
}

void Emulator::EmulateCycle() {
    // Fetch opcode
    opcode_ = memory_[pc_] << 8 | memory_[pc_ + 1];
    // Decode and execute opcode
    switch(opcode_ & 0xF000) {
        case 0xA000:
            index_ = opcode_ & 0xFFFF;
            pc_ = pc_ + 2;
            break;
        default:
            std::cout << "Unknown opcode: 0x" << std::hex << opcode_ << std::endl;
    }
    // Update timers
    if(delay_timer_ > 0) {
        --delay_timer_;
    }
    if(sound_timer_ > 0) {
        if(sound_timer_ == 1){
            std::cout << "BEEP!" << std::endl;
        }
    }
}

void Emulator::LoadGame(const std::string &gamename){
    // TODO: load game into memory
}

bool Emulator::draw_flag(){
    return draw_flag_;
}

void Emulator::SetKeys() {
    // TODO: Set key press state
}

}