#include <Window/window.h>

i32 main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});

    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        window.Swap();
    }
    return 0;
}
