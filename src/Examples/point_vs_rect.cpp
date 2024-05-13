#include "../Shapes/shapes.h"
#include "../Window/window.h"

using namespace ZipLib;

i32 main() {
    Window window(800, 800, "Point vs rect", true);
    Shapes::ColoredRect rect(glm::vec2(200, 600), 200, 200,
                             glm::vec4(1, 0, 0, 1));

    while (!window.ShouldClose()) {
        if (rect.rect.PointCollision(window.input.GetMousePos())) {
            rect.SetColor(glm::vec4(0, 1, 0, 1));
        } else {
            rect.SetColor(glm::vec4(1, 0, 0, 1));
        }
        window.Clear(10, 10, 10, 255);
        rect.Draw(*window.shader);
        window.Swap();
    }
}
