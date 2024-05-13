#pragma once

#include <array>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include "../Utilities/types.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace ZipLib::Core {

    // Manages all input, provides api for getting mouse and keyboard state
    class Input {
      private:
        std::array<bool, 316> key_states;
        bool mouse_state[2];
        glm::vec2 mouse_pos;

      private:
        static void InputCallback(GLFWwindow *window, i32 key, i32 scancode,
                                  i32 action, i32 mods);
        static void CursorPositionCallback(GLFWwindow *window, double xpos,
                                           double ypos);
        static void MouseButtonCallback(GLFWwindow *window, int button,
                                        int action, int mods);

      public:
        Input();
        // Setups all callbacks for getting input
        void Setup(GLFWwindow *window);
        bool KeyDown(GLenum key) const;
        bool MouseKeyDown(GLenum button) const;
        glm::vec2 GetMousePos();
    };
} // namespace ZipLib::Core
