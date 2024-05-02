#pragma once

#include <cglm/struct.h>
#include <glad/glad.h>
#include <optional>

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
public:
    Shader();
    void SetProjection(vec2s size, vec2s zBounds);
    void Use();
    // TODO: Functions for all uniforms
    void SetUniform(mat4 data, const char* name);
    void SetUniform(vec3s data, const char* name);
    void SetUniform(vec2s data, const char* name);

    void SetShader(ShaderType type);
};
