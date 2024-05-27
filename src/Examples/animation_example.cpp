#include "../Shapes/animated_rect.h"
#include "../Window/window.h"
#include "glad/glad.h"

i32 main() {
    ZipLib::Window window(800, 800, "Hello world!");
    ZipLib::Shapes::AnimatedRect rect(
        glm::vec2(200, 400), 64, 64, window.shader, "assets/sprites/orange", 2,
        GL_NEAREST, GL_RGBA8, window.resource_manager);

    i32 i = 0;
    while (!window.ShouldClose()) {
        if (i % 60 == 0) {
            rect.Advance();
        }
        window.Clear(24, 24, 24, 255);
        rect.Draw();
        window.Swap();
        i++;
    }
    return 0;
}