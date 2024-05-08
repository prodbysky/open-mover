#pragma once

#include "glm/ext/vector_float2.hpp"
#include <array>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "types.h"

namespace StintaEngine::Core {
    using namespace Types;

    // Manages all input, provides api for getting mouse and keyboard state
    class Input {
    private:
        std::array<bool, 316> key_states;
        bool mouse_state[2];
        glm::vec2 mouse_pos;
    private:
        static void InputCallback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
        static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
        static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    public:
        Input();
        // Setups all callbacks for getting input
        void Setup(GLFWwindow* window);
        bool KeyDown(GLenum key) const;
        bool MouseKeyDown(GLenum button) const;
        glm::vec2 GetMousePos();
    };
}
