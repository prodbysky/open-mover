#include "../Window/timer.h"
#include "../Window/window.h"

i32 main() {
    ZipLib::Window window(800, 800, "Hello world!");
    ZipLib::Sound synth =
        window.resource_manager.LoadSound("assets/sounds/synth.wav");
    ZipLib::Timer timer(1.0f);
    timer.Start();

    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        timer.Tick(window.GetDeltaTime());
        if (timer.Finished()) {
            window.audio.Play(synth);
            timer.Extend(5);
            timer.Stop();
        }
        window.Swap();
    }
    return 0;
}
