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
        static const int kScreenSize = 64 * 32;
        void Op0NNN(unsigned short opcode);
        void Op1NNN(unsigned short opcode);
        void Op2NNN(unsigned short opcode);
        void Op3NNN(unsigned short opcode);
        void Op4NNN(unsigned short opcode);
        void Op5NNN(unsigned short opcode);
        void Op6NNN(unsigned short opcode);
        void Op7NNN(unsigned short opcode);
        void Op8NNN(unsigned short opcode);
        void Op9NNN(unsigned short opcode);
        void OpANNN(unsigned short opcode);
        void OpBNNN(unsigned short opcode);
        void OpCNNN(unsigned short opcode);
        void OpDNNN(unsigned short opcode);
        void OpENNN(unsigned short opcode);
        void OpFNNN(unsigned short opcode);
        
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
        unsigned char screen_[kScreenSize];

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
