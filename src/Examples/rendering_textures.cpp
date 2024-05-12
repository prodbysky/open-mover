#include "../Shapes/textured_rect.h"
#include "../Window/window.h"

int main() {
    StintaEngine::Window window(800, 800, "Hello world!", false);
    
    const StintaEngine::Core::TextureData& orange = window.resource_manager.LoadTexture(std::string("assets/sprites/orange.png"));
    StintaEngine::Shapes::TexturedRect texture(glm::vec2(0, 800), 800, 800, orange, GL_NEAREST, GL_RGBA8);
    
    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        texture.Draw(*window.shader);
        window.Swap();
    }
    return 0;
}
