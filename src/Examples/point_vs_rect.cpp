#include "../Window/window.h"
#include "../Shapes/colored_rect.h"
#include <iostream>

using namespace StintaEngine;

i32 main() {
    Window window(800, 800, "Point vs rect", true);
    Shapes::ColoredRect rect(glm::vec2(200, 600), 200, 200, glm::vec3(1, 0, 0));

    while (!window.ShouldClose()) {
        if (rect.rect.PointCollision(window.input.GetMousePos())) {
            rect.SetColor(glm::vec3(0, 1, 0));
        } else {
            rect.SetColor(glm::vec3(1, 0, 0));
        }
        window.Clear(10, 10, 10, 255);
        rect.Draw(*window.shader);
        window.Swap();
    }
}
