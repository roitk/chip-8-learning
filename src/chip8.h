#pragma once
#include <string>

namespace chip8 {

// Main emulator class
class Emulator {
    public:
        void Initialize();
        void EmulateCycle();
        void LoadGame(const std::string &gamename);
        void SetKeys();
        bool draw_flag();
    private:
        // Current opcode
        unsigned short opcode_;

        // System memory
        unsigned char memory_[4096];
        // Registers
        unsigned char registers_[16];

        // Index
        unsigned short index_;

        // Program counter
        unsigned short pc_;

        // Screen
        unsigned char screen_[64 * 32];

        // Timers
        unsigned char delay_timer_;
        unsigned char sound_timer_;

        // Stack
        unsigned short stack_[16];
        unsigned short sp_;

        // Keyboard -- CHIP-8 only has 16 keys
        unsigned char key_[16];

        // Draw flag
        bool draw_flag_;
};

}
