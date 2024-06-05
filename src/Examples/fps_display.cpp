#include "../Core/ZipLib.h"
#include "../UI/UI.h"
#include "../Window/window.h"

int main() {
    ZipLib::Window window(800, 800, "Hello world!", true);
    const ZipLib::Font& font =
        ZipLib::ResourceManager.LoadFont("assets/fonts/arial.ttf", 48);
    ZipLib::UI::Text fps_display(font, "", glm::vec2(400, 400),
                                 glm::vec3(1, 1, 1), 1);

    u32 i = 0;

    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);

        if (i % 10 == 0) {
            fps_display.SetText(std::to_string((u32) window.GetFPS()));
        }
        fps_display.Draw(window.renderer);
        window.Swap();
        i++;
    }
    return 0;
}
