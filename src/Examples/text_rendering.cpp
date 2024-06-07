#include "../Core/ZipLib.h"
#include "../UI/UI.h"
#include "../Window/window.h"

int main() {
    ZipLib::Window window(
        {.width = 800, .height = 800, .title = "Hello world!", .v_sync = true});
    ZipLib::Font arial =
        ZipLib::ResourceManager.LoadFont("assets/fonts/arial.ttf", 96);
    ZipLib::UI::Text text(arial, "2024 MUSIC", glm::vec2(300, 200),
                          glm::vec3(1, 1, 1), 1);

    f64 amplitude = 500.0;
    f64 frequency = 5.0;

    while (!window.ShouldClose()) {
        f64 y_offset = sin(window.GetTotalTime() * frequency) * amplitude *
                       window.GetDeltaTime();
        text.SetPos(glm::vec2(200, 300 + y_offset));
        window.renderer.Clear(24, 24, 24, 255);
        text.Draw(window.renderer);
        window.Swap();
    }
    return 0;
}
