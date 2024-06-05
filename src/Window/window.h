#pragma once

#include "renderer.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace ZipLib {
    class Window {
    public:
        // Initializes GLFW context, all subsystems, setups debugging messages,
        // sets projection matrices for all of the shaders
        Window(u16 width, u16 height, const char* title, bool vSync = true);
        ~Window();
        // Swaps buffers, and polls for inputs
        void Swap();
        bool ShouldClose() const;
        f64 GetDeltaTime() const;
        f64 GetFPS() const;
        f64 GetTotalTime() const;

    public:
        GLFWwindow* window;
        Renderer renderer;

    private:
        f64 deltaTime;
        f64 lastFrame;
        f64 totalTime;
    };
} // namespace ZipLib
