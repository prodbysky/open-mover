#include "../Shapes/shapes.h"
#include "../Window/window.h"
#include "glad/glad.h"

#define SPEED 300

using namespace ZipLib;

void OrangeUpdate(Shapes::TexturedRect& orange, const Window& window);

i32 main() {
    Window window(800, 800, "Top-Down Movement", false);
    Core::TextureData orange_texture =
        window.resource_manager.LoadTexture("assets/sprites/orange.png");

    Shapes::TexturedRect orange(glm::vec2(368, 432), 128, 128, window.shader,
                                orange_texture, GL_NEAREST, GL_RGBA8);

    while (!window.ShouldClose()) {
        OrangeUpdate(orange, window);
        window.Clear(24, 24, 24, 255);
        orange.Draw();
        window.Swap();
    }
}

void OrangeUpdate(Shapes::TexturedRect& orange, const Window& window) {
    f32 speed = SPEED * window.GetDeltaTime();
    if (window.input.KeyDown(GLFW_KEY_A)) {
        orange.Move(glm::vec2(-speed, 0));
    }

    if (window.input.KeyDown(GLFW_KEY_D)) {
        orange.Move(glm::vec2(speed, 0));
    }

    if (window.input.KeyDown(GLFW_KEY_W)) {
        orange.Move(glm::vec2(0, speed));
    }

    if (window.input.KeyDown(GLFW_KEY_S)) {
        orange.Move(glm::vec2(0, -speed));
    }
}
