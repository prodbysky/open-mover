#include "../Shapes/shapes.h"
#include "../Window/window.h"

int main() {
    ZipLib::Window window(800, 800, "Hello world!", true);

    const ZipLib::Core::TextureData& orange =
        window.resource_manager.LoadTexture("assets/sprites/orange.png");
    ZipLib::Shapes::TexturedRect texture(glm::vec2(0, 800), 800, 800,
                                         window.shader, orange, GL_NEAREST,
                                         GL_RGBA8);
    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        texture.Draw();
        window.Swap();
    }
    return 0;
}
