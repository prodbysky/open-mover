#include "../Shapes/animated_rect.h"
#include "../Window/window.h"

i32 main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});
    ZipLib::Shapes::AnimatedRect rect(glm::vec2(200, 400), 64, 64,
                                      "assets/sprites/orange", 2, GL_NEAREST,
                                      GL_RGBA8);

    i32 i = 0;
    while (!window.ShouldClose()) {
        if (i % 60 == 0) {
            rect.Advance();
        }
        window.renderer.Clear(24, 24, 24, 255);
        rect.Draw(window.renderer);
        window.Swap();
        i++;
    }
    return 0;
}
