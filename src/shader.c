#include <stdlib.h>

#include <glad/glad.h>
#include <cglm/cglm.h>
#include <GLFW/glfw3.h>

#include "shader.h"

#include "util.h"

shader_t shader_new() {
    i32 success;
    char infoLog[512];

    const char* vertName = "quad_vertex.glsl";
    const char* defaultFragName = "default_quad_fragment.glsl";
    const char* textureFragName = "default_quad_fragment.glsl";

    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexSrc = read_entire_file(vertName);
    glShaderSource(vertexShader, 1, &vertexSrc, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("Failed to compile vertex shader: %s", infoLog);
    }

    u32 defaultFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* defaultFragmentSrc = read_entire_file(defaultFragName);
    glShaderSource(defaultFragmentShader, 1, &defaultFragmentSrc, NULL);
    glCompileShader(defaultFragmentShader);
    glGetShaderiv(defaultFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(defaultFragmentShader, 512, NULL, infoLog);
        printf("Failed to compile default fragment shader: %s", infoLog);
    }

    u32 textureFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* textureFragmentSrc = read_entire_file(textureFragName);
    glShaderSource(textureFragmentShader, 1, &textureFragmentSrc, NULL);
    glCompileShader(textureFragmentShader);
    glGetShaderiv(textureFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(textureFragmentShader, 512, NULL, infoLog);
        printf("Failed to compile texture fragment shader: %s", infoLog);
    }


    shader_t shader;
    shader.defaultID = glCreateProgram();
    shader.textureID = glCreateProgram();
    glAttachShader(shader.defaultID, vertexShader);
    glAttachShader(shader.defaultID, defaultFragmentShader);
    glAttachShader(shader.textureID, vertexShader);
    glAttachShader(shader.textureID, textureFragmentShader);
    glLinkProgram(shader.defaultID);
    glLinkProgram(shader.textureID);

    glDeleteShader(vertexShader);
    glDeleteShader(defaultFragmentShader);
    glDeleteShader(textureFragmentShader);
    free((void*)vertexSrc);
    free((void*)defaultFragmentSrc);
    free((void*)textureFragmentSrc);

    return shader;
}

void shader_set_current_shader(shader_t* shader, shader_type_e type) {
    switch (type) {
        case SHADER_DEFAULT: {
                shader->currentID = shader->defaultID;    
                break;
        }
        case SHADER_TEXTURE: {
                shader->currentID = shader->textureID;    
                break;
        }
    } 

    shader_use(*shader);
}

void shader_set_mat4f(shader_t shader, mat4 data, const char* name) {
    i32 uniform_location = glGetUniformLocation(shader.currentID, name); 

    if (uniform_location < 0) {
        printf("Tried to set non-existant shader uniform: %s", name);
        return;
    }

    shader_use(shader);
    glUniformMatrix4fv(uniform_location, 1, false, data[0]);
}

void shader_set_vec3f(shader_t shader, vec3s data, const char* name) {
    i32 uniform_location = glGetUniformLocation(shader.currentID, name); 

    if (uniform_location < 0) {
        printf("Tried to set non-existant shader uniform: %s", name);
        return;
    }

    shader_use(shader);
    glUniform3fv(uniform_location, 1, data.raw);
}

void shader_use(shader_t shader) {
    glUseProgram(shader.currentID);
}

void shader_set_projection(shader_t shader, vec2s size, vec2s zBounds) {
    mat4 proj;
    glm_ortho(0, size.x, 0, size.y, zBounds.x, zBounds.y, proj);
    shader_set_mat4f(shader, proj, "uProjection");
}
