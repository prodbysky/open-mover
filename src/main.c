#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

void resize_callback(GLFWwindow* window, int width, int height);
GLFWwindow* init(u16 width, u16 height, const char* title);


int main() {
    GLFWwindow* window = init(800, 800, "Hello world!");

    if (window == NULL) {
        return 0;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void resize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* init(u16 width, u16 height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Hello world!", NULL, NULL);

    if (window == NULL) {
        printf("Failed to create GLFW window!\n");
        return NULL;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("Failed to initialize GLEW\n");
        return NULL;
    }

    glfwSetFramebufferSizeCallback(window, resize_callback);

    glViewport(0, 0, width, height);
    return window;
}
