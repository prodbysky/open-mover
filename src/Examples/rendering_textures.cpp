#include "../Core/ZipLib.h"
#include "../Shapes/textured_rect.h"
#include "../Window/window.h"

int main() {
    ZipLib::Window window(800, 800, "Hello world!", true);

    const ZipLib::Core::TextureData& orange =
        ZipLib::ResourceManager.LoadTexture("assets/sprites/orange.png");
    ZipLib::Shapes::TexturedRect texture(glm::vec2(0, 800), 800, 800, orange,
                                         GL_NEAREST, GL_RGBA8);
    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        texture.Draw(window.renderer);
        window.Swap();
    }
    return 0;
}
