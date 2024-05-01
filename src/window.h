#pragma once

#include <memory>
#include <stdbool.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "types.h"
#include "input.h"
#include "audio.h"
#include "shader.h"

class Window {
public:
    GLFWwindow* window;
    Shader shader;
    Input input;
    Audio audio;
public:
    Window(u16 width, u16 height, const char* title);
    void Clear(u16 r, u16 b, u16 g, u16 a);
    void Swap();
    bool ShouldClose();
};
