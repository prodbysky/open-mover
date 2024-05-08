#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "window.h"

using namespace StintaEngine::Types;

int main() {
    StintaEngine::Window window(800, 800, "Hello world!", false);
    window.fontSystem->LoadFont("assets/fonts/arial.ttf", 96);
    
    if (window.window == nullptr) {
        return -1;
    }

    glm::vec2 pos = glm::vec2(300.0, 200.0);
    f64 amplitude = 100.0;
    f64 frequency = 5.0;

    while (!window.ShouldClose()) {
        f64 yOffset = sin(window.GetTotalTime() * frequency) * amplitude * window.GetDeltaTime();
        pos.y += yOffset;
        window.Clear(24, 24, 24, 255);
        window.fontSystem->Draw("assets/fonts/arial.ttf", *window.shader, "2024 MUSIC", pos, 1, glm::vec3(1, 1, 1));
        window.Swap();
    }
    return 0;
}
