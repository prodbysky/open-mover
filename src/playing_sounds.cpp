#include "window.h"

int main() {
    StintaEngine::Window window(800, 800, "Hello world!");
    
    window.audio.Play("assets/sounds/synth.wav");
    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        window.Swap();
    }
    return 0;
}
