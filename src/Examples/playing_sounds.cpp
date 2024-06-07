#include "../Core/ZipLib.h"
#include "../Window/window.h"

int main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});

    ZipLib::Audio.Play("assets/sounds/synth.wav");
    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        window.Swap();
    }
    return 0;
}
