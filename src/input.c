#include "input.h"

void input_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods) {
    (void) scancode;
    (void) mods;
    input_t* input = glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS) {
        input->keyStates[key - 32] = 1; 
    } else if (action == GLFW_RELEASE) {
        input->keyStates[key - 32] = 0;
    }
}

input_t input_new() {
    input_t input;
    memset(input.keyStates, 0, sizeof(input.keyStates));
    return input;
}

bool input_is_key_down(input_t input, i32 key) {
    return input.keyStates[key - 32];
}

void input_setup(input_t* input, GLFWwindow* window) {
    glfwSetWindowUserPointer(window, input);
    glfwSetKeyCallback(window, input_callback);
}
