#include "../Window/window.h"
#include "../Shapes/colored_rect.h"

using namespace StintaEngine;

i32 main() {
    Window window(800, 800, "Point vs rect", true);
    Shapes::ColoredRect rect1(glm::vec2(200, 600), 200, 200, glm::vec3(1, 0, 0));
    Shapes::ColoredRect rect2(glm::vec2(500, 600), 200, 200, glm::vec3(1, 0, 0));

    while (!window.ShouldClose()) {
        rect2.SetPos(glm::vec3(window.input.GetMousePos(), 0));
        if (rect1.rect.AABBCollision(rect2.rect)) {
            rect1.SetColor(glm::vec3(0, 1, 0));
        } else {
            rect1.SetColor(glm::vec3(1, 0, 0));
        }
        window.Clear(10, 10, 10, 255);
        rect1.Draw(*window.shader);
        rect2.Draw(*window.shader);
        window.Swap();
    }
}
