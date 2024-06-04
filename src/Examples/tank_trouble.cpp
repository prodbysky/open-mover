#include "../Shapes/shapes.h"
#include "../Window/window.h"
#include "glm/ext/vector_float2.hpp"

class Tank {
public:
    Tank(glm::vec2 position, glm::vec4 color) : rect(position, 64, 64, color) {
        velocity = {0, 0};
    }

    void Update() {}

    void Draw(ZipLib::Renderer& renderer) { rect.Draw(renderer); }

private:
    ZipLib::Shapes::ColoredRect rect;
    glm::vec2 velocity;
};

int main() {
    ZipLib::Window window(800, 800, "Hello world!");
    Tank tank({300, 300}, {1, 0, 1, 0});

    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        tank.Draw(window.renderer);
        window.Swap();
    }
    return 0;
}
