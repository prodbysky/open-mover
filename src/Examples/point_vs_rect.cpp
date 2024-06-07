#include "../Core/ZipLib.h"
#include "../Shapes/colored_rect.h"
#include "../Window/window.h"

using namespace ZipLib;

i32 main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});

    Shapes::ColoredRect rect(glm::vec2(200, 600), 200, 200,
                             glm::vec4(1, 0, 0, 1));

    while (!window.ShouldClose()) {
        if (rect.PointCollision(Input.GetMousePos())) {
            rect.SetColor(glm::vec4(0, 1, 0, 1));
        } else {
            rect.SetColor(glm::vec4(1, 0, 0, 1));
        }
        window.renderer.Clear(10, 10, 10, 255);
        rect.Draw(window.renderer);
        window.Swap();
    }
}
