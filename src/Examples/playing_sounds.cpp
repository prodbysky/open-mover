#include "../Window/window.h"
#include "../Resource/resources.h"

int main() {
    ZipLib::Window window(800, 800, "Hello world!");
    ZipLib::Sound synth = window.resource_manager.LoadSound("assets/sounds/synth.wav");
    
    window.audio.Play(synth);
    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        window.Swap();
    }
    return 0;
}
