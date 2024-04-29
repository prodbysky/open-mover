#include <stdio.h>

#include <glad/glad.h>

#include "window.h"
#include <GLFW/glfw3.h>

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
    glfwSwapInterval(1);

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

bool window_should_close(GLFWwindow* window) {
    return glfwWindowShouldClose(window);
}
