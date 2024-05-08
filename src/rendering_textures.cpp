#include "textured_rect.h"
#include "window.h"

int main() {
    StintaEngine::Window window(800, 800, "Hello world!");
    StintaEngine::TexturedRect texture(glm::vec2(200, 200), 128, 128, "assets/sprites/orange.png", GL_LINEAR, GL_RGBA8);
    
    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        texture.Draw(*window.shader);
        window.Swap();
    }
    return 0;
}
