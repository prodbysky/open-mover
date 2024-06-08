#include "input.h"

#include <Core/log.h>
#include <Utilities/assert.h>

namespace ZipLib::Core {
    Input::Input() {
        std::fill(key_states.begin(), key_states.end(), 0);
        std::fill(mouse_state.begin(), mouse_state.end(), 0);
    }

    void Input::Setup(GLFWwindow* window) {
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, InputCallback);
        glfwSetCursorPosCallback(window, CursorPositionCallback);
        glfwSetMouseButtonCallback(window, MouseButtonCallback);
        Log::Info("Succesfully setup input callbacks");
    }

    bool Input::KeyDown(GLenum key) const {
        Assert(key - 32 < key_states.size(), "Invalid key given");
        return key_states.at(key - 32);
    }

    bool Input::MouseKeyDown(GLenum button) const {
        switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            return mouse_state.at(0);
        case GLFW_MOUSE_BUTTON_RIGHT:
            return mouse_state.at(1);
        }
        return false;
    }

    glm::vec2 Input::GetMousePos() const { return mouse_pos; }

    bool Input::InputRuleDown(InputRule rule) {
        for (const auto& key : rule.keys) {
            if (KeyDown(key)) {
                return true;
            }
        }
        return false;
    }

    void Input::InputCallback(GLFWwindow* window, i32 key, i32 scancode,
                              i32 action, i32 mods) {

        (void) scancode;
        (void) mods;

        Input* input = (Input*) glfwGetWindowUserPointer(window);
        if (action == GLFW_PRESS) {
            input->key_states.at(key - 32) = 1;
        } else if (action == GLFW_RELEASE) {
            input->key_states.at(key - 32) = 0;
        }
    }

    void Input::CursorPositionCallback(GLFWwindow* window, double xpos,
                                       double ypos) {
        Input* input     = (Input*) glfwGetWindowUserPointer(window);
        input->mouse_pos = glm::vec2(xpos, 800 - ypos);
    }

    void Input::MouseButtonCallback(GLFWwindow* window, int button, int action,
                                    int mods) {
        (void) mods;
        Input* input = (Input*) glfwGetWindowUserPointer(window);
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            input->mouse_state.at(0) = action == GLFW_PRESS;
        }
        if (button == GLFW_MOUSE_BUTTON_RIGHT) {
            input->mouse_state.at(1) = action == GLFW_PRESS;
        }
    }
} // namespace ZipLib::Core
