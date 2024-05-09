#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "types.h"

namespace StintaEngine::Core {
    // All types of shaders
    enum class ShaderType {
        SHADER_DEFAULT,
        SHADER_TEXTURE,
        SHADER_FONT,
    };

    // Loads, compiles, links, manages shaders. Also can set uniforms on the current shader
    class Shader {
    private:
        u32 default_id;
        u32 texture_id;
        u32 font_id;
        u32 current_id;
    private:
        u32 CompileShader(const char* name, GLenum type) const;
        u32 GetUniformLocation(const char* name) const;
    public:
        Shader();
        // Sets the projection uniform for the current set shader
        void SetProjection(glm::vec2 size, glm::vec2 z_bounds);
        void Use() const;
        // TODO: Functions for all uniforms
        void SetUniform(glm::mat4 data, const char* name);
        void SetUniform(glm::vec3 data, const char* name);
        void SetUniform(glm::vec2 data, const char* name);
        void SetUniform(f32 x, f32 y, f32 z, const char* name);
        void SetShader(ShaderType type);
    };
}
