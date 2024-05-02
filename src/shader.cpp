#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

#include "util.h"

Shader::Shader() {
    const char* vertName = "quad_vertex.glsl";
    const char* defaultFragName = "default_quad_fragment.glsl";
    const char* textureFragName = "texture_quad_fragment.glsl";

    u32 vertexShader = CompileShader(vertName, GL_VERTEX_SHADER);
    u32 defaultFragShader = CompileShader(defaultFragName, GL_FRAGMENT_SHADER);
    u32 textureFragShader = CompileShader(textureFragName, GL_FRAGMENT_SHADER);

    defaultID = glCreateProgram();
    textureID = glCreateProgram();
    glAttachShader(defaultID, vertexShader);
    glAttachShader(defaultID, defaultFragShader);
    glAttachShader(textureID, vertexShader);
    glAttachShader(textureID, textureFragShader);
    glLinkProgram(defaultID);
    glLinkProgram(textureID);

    glDeleteShader(vertexShader);
    glDeleteShader(defaultFragShader);
    glDeleteShader(textureFragShader);
}

u32 Shader::CompileShader(const char* name, GLenum type) {
    i32 success;
    char infoLog[512];

    u32 shader = glCreateShader(type);
    std::string src = read_entire_file(name);
    const char* s = src.c_str();
    glShaderSource(shader, 1, &s, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Failed to compile " << name << ": " << infoLog << '\n';
    }
    
    return shader;
}

void Shader::SetShader(ShaderType type) {
    switch (type) {
        case SHADER_DEFAULT: {
                currentID = defaultID;    
                break;
        }
        case SHADER_TEXTURE: {
                currentID = textureID;    
                break;
        }
    } 

    Use();
}

void Shader::SetUniform(glm::mat4 data, const char* name) {
    i32 uniform_location = glGetUniformLocation(currentID, name); 

    if (uniform_location < 0) {
        std::cerr << "Tried to set non-existant shader uniform: " << name;
        return;
    }

    Use();
    glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(data));
    
}

void Shader::SetUniform(glm::vec3 data, const char* name) {
    i32 uniform_location = glGetUniformLocation(currentID, name); 

    if (uniform_location < 0) {
        std::cerr << "Tried to set non-existant shader uniform: " << name;
        return;
    }

    Use();
    glUniform3fv(uniform_location, 1, glm::value_ptr(data));
}


void Shader::SetUniform(glm::vec2 data, const char* name) {
    i32 uniform_location = glGetUniformLocation(currentID, name); 

    if (uniform_location < 0) {
        std::cerr << "Tried to set non-existant shader uniform: " << name;
        return;
    }

    Use();
    glUniform2fv(uniform_location, 1, glm::value_ptr(data));
}

void Shader::Use() {
    glUseProgram(currentID);
}

void Shader::SetProjection(glm::vec2 size, glm::vec2 zBounds) {
    Shader::SetUniform(glm::ortho(0.0f, size.x, 0.0f, size.y, zBounds.x, zBounds.y), "uProjection");
}
