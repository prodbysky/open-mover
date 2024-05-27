#include "../UI/UI.h"
#include "../Window/window.h"

int main() {
    ZipLib::Window window(800, 800, "Hello world!", true);
    ZipLib::Font arial =
        window.resource_manager.LoadFont("assets/fonts/arial.ttf", 96);
    ZipLib::UI::Text text(arial, "2024 MUSIC", glm::vec2(300, 200),
                          glm::vec3(1, 1, 1), 1, window.shader);

    f64 amplitude = 500.0;
    f64 frequency = 5.0;

    while (!window.ShouldClose()) {
        f64 y_offset = sin(window.GetTotalTime() * frequency) * amplitude *
                       window.GetDeltaTime();
        text.SetPos(glm::vec2(200, 300 + y_offset));
        window.Clear(24, 24, 24, 255);
        text.Draw();
        window.Swap();
    }
    return 0;
}
