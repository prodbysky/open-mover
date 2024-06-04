#include "../Window/window.h"

int main() {
    ZipLib::Window window(800, 800, "Hello world!");

    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        window.Swap();
    }
    return 0;
}
