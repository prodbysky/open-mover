#include "input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <algorithm>

Input::Input() {
    std::fill(keyStates.begin(), keyStates.end(), 0);
    mouseState[0] = 0;
    mouseState[1] = 0;
}

void Input::Setup(GLFWwindow* window) {
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, InputCallback);
    glfwSetCursorPosCallback(window, CursorPositionCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
}

bool Input::KeyDown(GLenum key) {
    return keyStates[key - 32];
}
bool Input::MouseKeyDown(GLenum button) {
    switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            return mouseState[0];
        case GLFW_MOUSE_BUTTON_RIGHT:
            return mouseState[1];
    }
    return false;
}

glm::vec2 Input::GetMousePos() {
    return mousePos;
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

void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    Input* input = (Input*)glfwGetWindowUserPointer(window);
    input->mousePos = glm::vec2(xpos, ypos);
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    (void) mods;
    Input* input = (Input*)glfwGetWindowUserPointer(window);
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        input->mouseState[0] = action == GLFW_PRESS;
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        input->mouseState[1] = action == GLFW_PRESS;
    }
}
