#include "chip8.h"
#include <termios.h>

chip8::Emulator emulator;

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