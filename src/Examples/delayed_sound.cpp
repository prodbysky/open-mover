#include "../Core/ZipLib.h"
#include "../Window/timer.h"
#include "../Window/window.h"

i32 main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});
    ZipLib::Timer timer(1.0f);
    timer.Start();

    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        timer.Tick(window.GetDeltaTime());
        if (timer.Finished()) {
            ZipLib::Audio.Play("assets/sounds/synth.wav");
            timer.Extend(2);
        }
        window.Swap();
    }
    return 0;
}
