#include "input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <algorithm>

namespace StintaEngine::Core {
    Input::Input() {
        std::fill(key_states.begin(), key_states.end(), 0);
        mouse_state[0] = 0;
        mouse_state[1] = 0;
    }

    void Input::Setup(GLFWwindow* window) {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, InputCallback);
        glfwSetCursorPosCallback(window, CursorPositionCallback);
        glfwSetMouseButtonCallback(window, MouseButtonCallback);
    }

    bool Input::KeyDown(GLenum key) const {
        return key_states[key - 32];
    }

    bool Input::MouseKeyDown(GLenum button) const {
        switch (button) {
            case GLFW_MOUSE_BUTTON_LEFT:
                return mouse_state[0];
            case GLFW_MOUSE_BUTTON_RIGHT:
                return mouse_state[1];
        }
        return false;
    }

    glm::vec2 Input::GetMousePos() {
        return mouse_pos;
    }

    void Input::InputCallback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods) {
        (void) scancode;
        (void) mods;
        Input* input = (Input*)glfwGetWindowUserPointer(window);

        if (action == GLFW_PRESS) {
            input->key_states[key - 32] = 1; 
        } else if (action == GLFW_RELEASE) {
            input->key_states[key - 32] = 0;
        }
    }

    void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
        Input* input = (Input*)glfwGetWindowUserPointer(window);
        input->mouse_pos = glm::vec2(xpos, ypos);
    }

    void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        (void) mods;
        Input* input = (Input*)glfwGetWindowUserPointer(window);
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            input->mouse_state[0] = action == GLFW_PRESS;
        }
        if (button == GLFW_MOUSE_BUTTON_RIGHT) {
            input->mouse_state[1] = action == GLFW_PRESS;
        }
    }
}
