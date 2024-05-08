#pragma once

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "types.h"
#include "input.h"
#include "audio.h"
#include "shader.h"
#include "font_system.h"

namespace StintaEngine {
    using namespace Types;
    class Window {
    public:
        GLFWwindow* window;
        std::unique_ptr<Core::Shader> shader;
        Core::Input input;
        std::unique_ptr<Core::FontSystem> font_system;
        Core::Audio audio;
    public:
        // Initializes GLFW context, all subsystems, setups debugging messages, sets projection matrices for all of the shaders
        Window(u16 width, u16 height, const char* title, bool vSync = true);
        ~Window();
        void Clear(u16 r, u16 b, u16 g, u16 a);
        // Swaps buffers, and polls for inputs
        void Swap() const;
        bool ShouldClose() const;
        f64 GetDeltaTime() const;
        f64 GetFPS() const;
        f64 GetTotalTime() const;
    private:
        f64 deltaTime;
        f64 lastFrame;
        f64 totalTime;
    private:
        static void MessageCallback(GLenum src, GLenum type, GLuint id, GLenum severity, GLsizei len, GLchar const* message, void const* user_param);
    };
}
