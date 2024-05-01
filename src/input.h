#pragma once

#include <array>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>


#include "types.h"

class Input {
private:
    std::array<bool, 316> keyStates;
private:
    static void InputCallback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
public:
    Input();
    void Setup(GLFWwindow* window);
    bool KeyDown(GLenum key);
};
