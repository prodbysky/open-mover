#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"

#include "Window/window.h"

int main() {
    StintaEngine::Window window(800, 800, "Hello world!", true);
    StintaEngine::Font arial = window.font_system->LoadFont("assets/fonts/arial.ttf", 96);
    
    glm::vec2 pos = glm::vec2(300.0, 200.0);
    f64 amplitude = 100.0;
    f64 frequency = 5.0;

    while (!window.ShouldClose()) {
        f64 yOffset = sin(window.GetTotalTime() * frequency) * amplitude * window.GetDeltaTime();
        pos.y += yOffset;
        window.Clear(24, 24, 24, 255);
        window.font_system->Draw(arial, *window.shader, "2024 MUSIC", pos, 1, glm::vec3(1, 1, 1));
        window.Swap();
    }
    return 0;
}
