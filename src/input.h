#ifndef INPUT_H
#define INPUT_H

#include <string.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>

#include "types.h"

typedef struct {
    bool keyStates[316];
} input_t;

void input_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);

input_t input_new();

bool input_is_key_down(input_t input, i32 key); 

void input_setup(input_t* input, GLFWwindow* window);

#endif // INPUT_H
