#pragma once

#include <memory>
#include <stdbool.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "types.h"
#include "input.h"
#include "audio.h"
#include "shader.h"
#include "font_system.h"

class Window {
public:
    GLFWwindow* window;
    std::unique_ptr<Shader> shader;
    Input input;
    std::unique_ptr<FontSystem> fontSystem;
    Audio audio;
private:
    f64 deltaTime;
    f64 lastFrame;
    f64 totalTime;
private:
    static void MessageCallback(GLenum src, GLenum type, GLuint id, GLenum severity, GLsizei len, GLchar const* message, void const* user_param);
public:
    Window(u16 width, u16 height, const char* title, bool vSync = true);
    ~Window();
    void Clear(u16 r, u16 b, u16 g, u16 a);
    void Swap();
    bool ShouldClose();
    f64 GetDeltaTime();
    f64 GetTotalTime();
};
