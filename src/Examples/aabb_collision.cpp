#include "../Core/ZipLib.h"
#include "../Shapes/colored_rect.h"
#include "../Window/window.h"

using namespace ZipLib;

i32 main() {
    Window window(800, 800, "Point vs rect", true);
    Shapes::ColoredRect rect1(glm::vec2(200, 600), 200, 200,
                              glm::vec4(1, 0, 0, 1));
    Shapes::ColoredRect rect2(glm::vec2(500, 600), 200, 200,
                              glm::vec4(1, 0, 0, 0.25));

    while (!window.ShouldClose()) {
        rect2.SetPos(glm::vec3(Input.GetMousePos(), 0));
        if (rect1.AABBCollision(rect2)) {
            rect1.SetColor(glm::vec4(0, 1, 0, 1));
        } else {
            rect1.SetColor(glm::vec4(1, 0, 0, 1));
        }
        window.renderer.Clear(10, 10, 10, 255);
        rect1.Draw(window.renderer);
        rect2.Draw(window.renderer);
        window.Swap();
    }
}
