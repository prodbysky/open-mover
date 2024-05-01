#pragma once

#include <memory>
#include <stdbool.h>
#include <GLFW/glfw3.h>

#include "types.h"
#include "input.h"
#include "audio.h"
#include "shader.h"

class Window {
private:
    GLFWwindow* window;
    Shader shader;
    std::unique_ptr<Input> input;
    std::unique_ptr<Audio> audio;
public:
    Window(u16 width, u16 height, const char* title);
    void Clear(u16 r, u16 b, u16 g, u16 a);
    void Swap();
    void ShouldClose();
};
