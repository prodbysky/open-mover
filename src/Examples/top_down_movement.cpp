#include "../Core/ZipLib.h"
#include "../Shapes/textured_rect.h"
#include "../Window/window.h"

#define SPEED 300

using namespace ZipLib;

void OrangeUpdate(Shapes::TexturedRect& orange, const Window& window);

i32 main() {
    Window window(800, 800, "Top-Down Movement", false);
    Core::TextureData orange_texture =
        ResourceManager.LoadTexture("assets/sprites/orange.png");

    Shapes::TexturedRect orange(glm::vec2(368, 432), 128, 128, orange_texture,
                                GL_NEAREST, GL_RGBA8);

    while (!window.ShouldClose()) {
        OrangeUpdate(orange, window);
        window.renderer.Clear(24, 24, 24, 255);
        orange.Draw(window.renderer);
        window.Swap();
    }
}

void OrangeUpdate(Shapes::TexturedRect& orange, const Window& window) {
    f32 speed = SPEED * window.GetDeltaTime();
    if (Input.KeyDown(GLFW_KEY_A)) {
        orange.Move(glm::vec2(-speed, 0));
    }

    if (Input.KeyDown(GLFW_KEY_D)) {
        orange.Move(glm::vec2(speed, 0));
    }

    if (Input.KeyDown(GLFW_KEY_W)) {
        orange.Move(glm::vec2(0, speed));
    }

    if (Input.KeyDown(GLFW_KEY_S)) {
        orange.Move(glm::vec2(0, -speed));
    }
}
