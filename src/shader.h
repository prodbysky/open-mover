#pragma once

#include <glad/glad.h>
#include <optional>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "types.h"

enum ShaderType {
    SHADER_DEFAULT,
    SHADER_TEXTURE,
};

class Shader {
private:
    u32 defaultID;
    u32 textureID;
    u32 currentID;

    u32 CompileShader(const char* name, GLenum type);
    u32 GetUniformLocation(const char* name);
public:
    Shader();
    void SetProjection(glm::vec2 size, glm::vec2 zBounds);
    void Use();
    // TODO: Functions for all uniforms
    void SetUniform(glm::mat4 data, const char* name);
    void SetUniform(glm::vec3 data, const char* name);
    void SetUniform(glm::vec2 data, const char* name);

    void SetShader(ShaderType type);
};
