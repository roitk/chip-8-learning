#include "chip8.h"

chip8::Emulator emulator;

void SetupGraphics(){
    // TODO: Stub for GLUT implementation
}

void SetupInput() {
    // TODO: Bind callbacks
}

void DrawGraphics() {
    // TODO: Stub for GLUT implementation
}

int main(int argc, char **argv){
    SetupGraphics();
    SetupInput();

    emulator.LoadGame("pong");

    for(;;){
        // One cycle
        emulator.EmulateCycle();

        if(emulator.draw_flag()){
            DrawGraphics();
        }

        // Store key press state () 
        emulator.SetKeys();
    }
}