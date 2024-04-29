#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "rect.h"
#include "shader.h"
#include "types.h"

void resize_callback(GLFWwindow* window, i32 width, i32 height);
GLFWwindow* window_init(u16 width, u16 height, const char* title);
void window_clear(u16 r, u16 b, u16 g, u16 a);
void window_swap(GLFWwindow* window);

int main() {
    GLFWwindow* window = window_init(800, 800, "Hello world!");

    if (window == NULL) {
        return 0;
    }

    u32 shader = shader_new("vertex.glsl", "fragment.glsl");

    rect_t rect = rect_new((vec2s){.x = 200, .y = 600}, 200, 200, (vec3s){.r = 1, .g = 1, .b = 1});

    mat4 proj;
    glm_ortho(0.0f, 800.0f, 0.0f, 800.0f, -1.5f, 1.5f, proj);
    shader_set_mat4f(shader, proj, "uMVP");

    while (!glfwWindowShouldClose(window)) {
        window_clear(24, 24, 24, 255);
        glUseProgram(shader);
        
        glBindVertexArray(rect.VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        window_swap(window);
    }

    glfwTerminate();
    return 0;
}

void resize_callback(GLFWwindow* window, i32 width, i32 height) {
    (void) window;
    glViewport(0, 0, width, height);
}

GLFWwindow* window_init(u16 width, u16 height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (window == NULL) {
        printf("Failed to create GLFW window!\n");
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD");
        return NULL;
    }

    glfwSetFramebufferSizeCallback(window, resize_callback);

    glViewport(0, 0, width, height);
    return window;
}

void window_clear(u16 r, u16 b, u16 g, u16 a) {
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void window_swap(GLFWwindow* window) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}
