#include <stdlib.h>

#include <glad/glad.h>
#include <cglm/cglm.h>
#include <GLFW/glfw3.h>

#include "shader.h"

#include "util.h"

shader_t shader_new(const char* vertexSource, const char* fragmentSource) {
    i32 success;
    char infoLog[512];

    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSrc = read_entire_file(vertexSource);
    glShaderSource(vertexShader, 1, &vertexSrc, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("Failed to compile vertex shader: %s", infoLog);
    }

    u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentSrc = read_entire_file(fragmentSource);
    glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("Failed to compile fragment shader: %s", infoLog);
    }


    shader_t shader = glCreateProgram();
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

void shader_set_mat4f(shader_t shader, mat4 data, const char* name) {
    i32 uniform_location = glGetUniformLocation(shader, name); 

    if (uniform_location < 0) {
        printf("Tried to set non-existant shader uniform: %s", name);
        return;
    }

    glUseProgram(shader);
    glUniformMatrix4fv(uniform_location, 1, false, data[0]);
}

void shader_set_vec3f(shader_t shader, vec3s data, const char* name) {
    i32 uniform_location = glGetUniformLocation(shader, name); 

    if (uniform_location < 0) {
        printf("Tried to set non-existant shader uniform: %s", name);
        return;
    }

    glUseProgram(shader);
    glUniform3fv(uniform_location, 1, data.raw);
}

void shader_use(shader_t shader) {
    glUseProgram(shader);
}

void shader_set_projection(shader_t shader, vec2s size, vec2s zBounds) {
    mat4 proj;
    glm_ortho(0, size.x, 0, size.y, zBounds.x, zBounds.y, proj);
    shader_set_mat4f(shader, proj, "uProjection");
}
