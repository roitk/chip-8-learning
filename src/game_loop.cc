#include "chip8.h"

chip8::Emulator emulator;

int main(int argc, char **argv){
    setupGraphics();
    setupInput();

    Emulator.Initialize();
    Emulator.LoadGame("pong");

    for(;;){
        // One cycle
        Emulator.EmulateCycle();

        if(Emulator.drawFlat){
            DrawGraphics();
        }

        // Store key press state () 
        Emulator.SetKeys();
    }
}