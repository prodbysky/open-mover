#pragma once

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../Core/core.h"
#include "../Resource/resource_manager.h"
#include "../Utilities/utilities.h"

namespace ZipLib {
    class Window {
    public:
        // Initializes GLFW context, all subsystems, setups debugging messages,
        // sets projection matrices for all of the shaders
        Window(u16 width, u16 height, const char* title, bool vSync = true);
        ~Window();
        void Clear(u8 r, u8 b, u8 g, u8 a);
        // Swaps buffers, and polls for inputs
        void Swap() const;
        bool ShouldClose() const;
        f64 GetDeltaTime() const;
        f64 GetFPS() const;
        f64 GetTotalTime() const;

    public:
        GLFWwindow* window;
        std::shared_ptr<Core::Shader> shader;

    private:
        f64 deltaTime;
        f64 lastFrame;
        f64 totalTime;
    };
} // namespace ZipLib
