#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "types.h"

void resize_callback(GLFWwindow* window, int width, int height);
GLFWwindow* init_window(u16 width, u16 height, const char* title);
u32 create_shader(const char* vertexSource, const char* fragmentSource);

float vertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
};

u32 indices[] = {
    0, 1, 3,
    1, 2, 3
};

int main() {
    GLFWwindow* window = init_window(800, 800, "Hello world!");

    if (window == NULL) {
        return 0;
    }

    u32 shader = create_shader("vertex.glsl", "fragment.glsl");

    u32 VAO;
    u32 VBO;
    u32 EBO;
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.09, 0.09, 0.09, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void resize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* init_window(u16 width, u16 height, const char* title) {
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

}

u32 create_shader(const char* vertexSource, const char* fragmentSource) {
    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSrc = read_entire_file(vertexSource);
    glShaderSource(vertexShader, 1, &vertexSrc, NULL);
    glCompileShader(vertexShader);

    u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentSrc = read_entire_file(fragmentSource);
    glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
    glCompileShader(fragmentShader);

    u32 shader = glCreateProgram();
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);
    glUseProgram(shader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    free((void*)vertexSrc);
    free((void*)fragmentSrc);

    return shader;
}
