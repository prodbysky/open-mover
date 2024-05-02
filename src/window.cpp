#include <glad/glad.h>

#include "window.h"
#include "GLFW/glfw3.h"
#include "types.h"
#include <iostream>

Window::Window(u16 width, u16 height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window!" << '\n';
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    gladLoadGL();

    glViewport(0, 0, width, height);
    
    input = Input();
    input.Setup(window);

    audio = Audio();

    shader = Shader(123);
    shader.SetShader(SHADER_DEFAULT);
    shader.SetProjection((vec2s){.x = f32(width), .y = f32(height)}, (vec2s){.x = -1.5, .y = 1.5});
    shader.SetShader(SHADER_TEXTURE);
    shader.SetProjection((vec2s){.x = f32(width), .y = f32(height)}, (vec2s){.x = -1.5, .y = 1.5});
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::Swap() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Clear(u16 r, u16 b, u16 g, u16 a) {
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
