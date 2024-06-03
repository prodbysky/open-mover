#include "../Core/ZipLib.h"
#include "../Window/timer.h"
#include "../Window/window.h"

i32 main() {
    ZipLib::Window window(800, 800, "Hello world!");
    ZipLib::Timer timer(1.0f);
    timer.Start();

    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        timer.Tick(window.GetDeltaTime());
        if (timer.Finished()) {
            ZipLib::Audio.Play("assets/sounds/synth.wav");
            timer.Extend(2);
        }
        window.Swap();
    }
    return 0;
}
