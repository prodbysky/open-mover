#include <math.h>
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

    u32 shader = shader_new("vertex.glsl", "fragment.glsl");

    rect_t rect = rect_new((vec2s){.x = 200, .y = 600}, 200, 200, (vec3s){.r = 0, .g = 0, .b = 0});

    mat4 proj;
    glm_ortho(0.0f, 800.0f, 0.0f, 800.0f, -1.5f, 1.5f, proj);
    shader_set_mat4f(shader, proj, "uProjection");

    while (!glfwWindowShouldClose(window)) {
        if (input_is_key_down(input, GLFW_KEY_SPACE)) {
            rect_move(&rect, (vec3s){.x = 1, .y = 0, .z = 0});
        }

        window_clear(24, 24, 24, 255);
        glUseProgram(shader);
        
        rect_draw(rect, shader);
        window_swap(window);
    }

    glfwTerminate();
    return 0;
}
