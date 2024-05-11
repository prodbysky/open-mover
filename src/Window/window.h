#pragma once

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../Utilities/types.h"
#include "../Core/input.h"
#include "../Core/audio.h"
#include "../Core/shader.h"
#include "../Resource/resource_manager.h"

namespace StintaEngine {
    class Window {
    public:
        GLFWwindow* window;
        std::unique_ptr<Core::Shader> shader;
        Core::Input input;
        Core::Audio audio;
        Core::ResourceManager resource_manager;
        FT_Library freetype; 
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
