#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <time.h>

#include "input.h"
#include "window.h"
#include "rect.h"
#include "shader.h"
#include "types.h"

int main() {
    GLFWwindow* window = window_init(800, 800, "Hello world!");

    if (window == NULL) {
        return 0;
    }

    input_t input = input_new();
    input_setup(&input, window);

    u32 shader = shader_new("color_quad_vertex.glsl", "color_quad_fragment.glsl");
    shader_set_projection(shader, (vec2s){.x = 800, .y = 800}, (vec2s){.x = -1.5, .y = 1.5});

    rect_t rect = rect_new((vec2s){.x = 200, .y = 600}, 80, 80, (vec3s){.r = 1, .g = 1, .b = 1});

    while (!window_should_close(window)) {
        window_clear(24, 24, 24, 255);
        
        rect_draw(rect, shader);
        window_swap(window);
    }

    glfwTerminate();
    return 0;
}
