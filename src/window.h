#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <GLFW/glfw3.h>

#include "types.h"
#include "input.h"
#include "audio.h"
#include "shader.h"

typedef struct {
    GLFWwindow* window;
    input_t input;
    audio_t* audio;
    shader_t shader;
} window_t;

void resize_callback(GLFWwindow* window, i32 width, i32 height);
window_t window_init(u16 width, u16 height, const char* title);
void window_clear(u16 r, u16 b, u16 g, u16 a);
void window_swap(window_t* window);
bool window_should_close(window_t* window);

#endif // WINDOW_H
