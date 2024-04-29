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

#define GRAVITY -.981

int main() {
    GLFWwindow* window = window_init(800, 800, "Hello world!");

    if (window == NULL) {
        return 0;
    }

    input_t input = input_new();
    input_setup(&input, window);

    u32 shader = shader_new("color_quad_vertex.glsl", "color_quad_fragment.glsl");

    rect_t rect = rect_new((vec2s){.x = 200, .y = 600}, 80, 80, (vec3s){.r = 1, .g = 1, .b = 1});

    mat4 proj;
    glm_ortho(0.0f, 800.0f, 0.0f, 800.0f, -1.5f, 1.5f, proj);
    shader_set_mat4f(shader, proj, "uProjection");

    while (!window_should_close(window)) {
        window_clear(24, 24, 24, 255);
        
        rect_draw(rect, shader);
        window_swap(window);
    }

    glfwTerminate();
    return 0;
}
