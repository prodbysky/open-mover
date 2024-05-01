#include <iostream>
#include <glad/glad.h>

#include "window.h"
#include "types.h"

Window::Window(u16 width, u16 height, const char* title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window!" << '\n';
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    gladLoadGL();

    glViewport(0, 0, width, height);
    
    input = std::make_unique<Input>();
    input->Setup(window);

    audio = std::make_unique<Audio>();
    if (audio == nullptr) {
        std::cerr << "Failed to initialize miniaudio engine" << '\n';
    }

    shader = Shader();
    shader.SetShader(SHADER_DEFAULT);
    shader.SetProjection((vec2s){.x = f32(width), .y = f32(height)}, (vec2s){.x = -1.5, .y = 1.5});
    shader.SetShader(SHADER_TEXTURE);
    shader.SetProjection((vec2s){.x = f32(width), .y = f32(height)}, (vec2s){.x = -1.5, .y = 1.5});
}
