#pragma once
#include <string>
#include <random>
#include <unordered_map>
#include <iostream>

namespace chip8 {

// Main emulator class
class Emulator {
    public:
        Emulator();
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

        // Random number generator
        std::default_random_engine rng;

        // Valid keys
        std::unordered_map<char, char> keypad_mapping_ = {
            {'1', '1'},
            {'2', '2'},
            {'3', '3'},
            {'4', 'c'},
            {'q', '4'},
            {'w', '5'},
            {'e', '6'},
            {'r', 'd'},
            {'a', '7'},
            {'s', '8'},
            {'d', '9'},
            {'f', 'e'},
            {'z', 'a'},
            {'x', '0'},
            {'c', 'b'},
            {'v', 'f'}
        };
};

}