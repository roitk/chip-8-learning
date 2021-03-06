#include "chip8.h"
#include <iostream>
#include <chrono>
#include <termios.h>

namespace chip8 {

Emulator::Emulator() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rng = std::default_random_engine(seed);
    pc_ = 0x200;
    index_ = 0;
    pc_ = 0;
}

void Emulator::EmulateCycle() {
    // Fetch opcode
    unsigned short opcode = memory_[pc_] << 8 | memory_[pc_ + 1];
    // Decode and execute opcode
    int cmdIndex = (opcode & 0xF000) >> 12;

    // Array of function pointers to op commands
    void (Emulator::*optable[16]) (unsigned short) = {
        &chip8::Emulator::Op0NNN,
        &chip8::Emulator::Op1NNN,
        &chip8::Emulator::Op2NNN,
        &chip8::Emulator::Op3NNN,
        &chip8::Emulator::Op4NNN,
        &chip8::Emulator::Op5NNN,
        &chip8::Emulator::Op6NNN,
        &chip8::Emulator::Op7NNN,
        &chip8::Emulator::Op8NNN,
        &chip8::Emulator::Op9NNN,
        &chip8::Emulator::OpANNN,
        &chip8::Emulator::OpBNNN,
        &chip8::Emulator::OpCNNN,
        &chip8::Emulator::OpDNNN,
        &chip8::Emulator::OpENNN,
        &chip8::Emulator::OpFNNN
    };

    // Call the correct operator based on the most significant nibble of the opcode
    (this->*(optable[cmdIndex]))(opcode);

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

void SetupGraphics(){
    // TODO: Stub for GLUT implementation
}

void SetupInput() {
    // Using the termios header, we set up input to not require an ENTER press after each keystroke
    // We may not need this when we start doing GLUT
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &t);
    // TODO: Bind callbacks
}

void DrawGraphics() {
    // TODO: Stub for GLUT implementation
}

void Emulator::Start() {
    SetupGraphics();
    SetupInput();

    for(;;){
        // One cycle
        EmulateCycle();

        if(draw_flag()){
            DrawGraphics();
        }

        // Store key press state () 
        SetKeys();
    }
}

}