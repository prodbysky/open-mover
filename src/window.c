#include <stdio.h>

#include <glad/glad.h>

#include "window.h"
#include "input.h"
#include <GLFW/glfw3.h>

void resize_callback(GLFWwindow* window, i32 width, i32 height) {
    (void) window;
    glViewport(0, 0, width, height);
}

window_t window_init(u16 width, u16 height, const char* title) {
    window_t window;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window.window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (window.window == NULL) {
        printf("Failed to create GLFW window!\n");
    }

    glfwMakeContextCurrent(window.window);
    glfwSwapInterval(1);

    gladLoadGL();

    glfwSetFramebufferSizeCallback(window.window, resize_callback);

    glViewport(0, 0, width, height);
    
    window.input = input_new();
    input_setup(&window.input, window.window);
    window.audio = audio_new();
    if (window.audio == NULL) {
        printf("Failed to initialize miniaudio engine");
    }

    return window;
}

void window_clear(u16 r, u16 b, u16 g, u16 a) {
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void window_swap(window_t* window) {
    glfwSwapBuffers(window->window);
    glfwPollEvents();
}

bool window_should_close(window_t* window) {
    return glfwWindowShouldClose(window->window);
}

bool window_is_key_down(window_t window, GLenum key) {
    return window.input.keyStates[key - 32];
}
