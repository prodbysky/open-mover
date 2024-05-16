#include "../Resource/animation.h"
#include "../Shapes/textured_rect.h"
#include "../Window/window.h"
#include "glad/glad.h"

i32 main() {
    ZipLib::Window window(800, 800, "Hello world!");
    ZipLib::Animation animation("assets/sprites/orange", 2, GL_MIRRORED_REPEAT,
                                GL_NEAREST, GL_RGBA8, window.resource_manager);
    ZipLib::Shapes::TexturedRect rect(glm::vec2(200, 400), 64, 64, {},
                                      GL_NEAREST, GL_RGBA8);
    rect.texture = animation.GetCurrentFrame();

    i32 i = 0;
    while (!window.ShouldClose()) {
        if (i % 60 == 0) {
            animation.Advance();
            rect.texture = animation.GetCurrentFrame();
        }
        window.Clear(24, 24, 24, 255);
        rect.Draw(*window.shader);
        window.Swap();
        i++;
    }
    return 0;
}
