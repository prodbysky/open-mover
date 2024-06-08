#include "../Core/ZipLib.h"
#include "../Shapes/textured_rect.h"
#include "../Window/window.h"
#include "Core/input.h"

#define SPEED 300

using namespace ZipLib;

void OrangeUpdate(Shapes::TexturedRect& orange, const Window& window);

i32 main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});

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
    if (Input.KeyDown(Core::Key::A)) {
        orange.Move(glm::vec2(-speed, 0));
    }

    if (Input.KeyDown(Core::Key::D)) {
        orange.Move(glm::vec2(speed, 0));
    }

    if (Input.KeyDown(Core::Key::W)) {
        orange.Move(glm::vec2(0, speed));
    }

    if (Input.KeyDown(Core::Key::S)) {
        orange.Move(glm::vec2(0, -speed));
    }
}
