#include "input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <algorithm>

Input::Input() {
    std::fill(keyStates.begin(), keyStates.end(), 0);
}

void Input::Setup(GLFWwindow* window) {
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, InputCallback);
}

void Input::InputCallback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods) {
    (void) scancode;
    (void) mods;
    Input* input = (Input*)glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS) {
        input->keyStates[key - 32] = 1; 
    } else if (action == GLFW_RELEASE) {
        input->keyStates[key - 32] = 0;
    }
}

bool Input::KeyDown(GLenum key) {
    return keyStates[key - 32];
}
