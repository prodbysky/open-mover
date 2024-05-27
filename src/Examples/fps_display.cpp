#include "../UI/UI.h"
#include "../Window/window.h"

#include <string>

int main() {
    ZipLib::Window window(800, 800, "Hello world!", true);
    const ZipLib::Font& font =
        window.resource_manager.LoadFont("assets/fonts/arial.ttf", 48);
    ZipLib::UI::Text fps_display(font, "", glm::vec2(400, 400),
                                 glm::vec3(1, 1, 1), 1, window.shader);

    u32 i = 0;

    while (!window.ShouldClose()) {
        window.Clear(24, 24, 24, 255);
        if (i % 10 == 0) {
            fps_display.SetText(std::to_string((u32) window.GetFPS()));
        }
        fps_display.Draw();
        window.Swap();
        i++;
    }
    return 0;
}
