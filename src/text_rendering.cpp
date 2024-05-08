#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "window.h"

int main() {
    Window window(800, 800, "Hello world!");
    window.fontSystem->LoadFont("assets/fonts/arial.ttf", 96);
    
    if (window.window == nullptr) {
        return -1;
    }

    glm::vec2 pos = glm::vec2(300, 200);
    float amplitude = 10.0f;
    float frequency = 0.5f;
    float time = 0.0f;

    while (!window.ShouldClose()) {
        float yOffset = sin(time * frequency) * amplitude;
        pos.y += yOffset;
        window.Clear(24, 24, 24, 255);
        window.fontSystem->Draw("assets/fonts/arial.ttf", *window.shader, "2024 MUSIC", pos, 1, glm::vec3(1, 1, 1));
        window.Swap();
        time += 0.1f;
    }
    return 0;
}
