#include "assert.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "../Core/shader.h"
#include "../Utilities/assert.h"
#include "../Utilities/util.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace ZipLib::Core {

    Shader::Shader() {
        const char* vert_name = "assets/shaders/quad_vertex.glsl";
        const char* default_frag_name =
            "assets/shaders/default_quad_fragment.glsl";
        const char* texture_frag_name =
            "assets/shaders/texture_quad_fragment.glsl";
        const char* font_vertex_name = "assets/shaders/font_vertex.glsl";
        const char* font_frag_name   = "assets/shaders/font_fragment.glsl";

        u32 vertex_shader = CompileShader(vert_name, GL_VERTEX_SHADER);
        u32 default_frag_shader =
            CompileShader(default_frag_name, GL_FRAGMENT_SHADER);
        u32 texture_frag_shader =
            CompileShader(texture_frag_name, GL_FRAGMENT_SHADER);
        u32 font_vert_shader =
            CompileShader(font_vertex_name, GL_VERTEX_SHADER);
        u32 font_frag_shader =
            CompileShader(font_frag_name, GL_FRAGMENT_SHADER);

        default_id = LinkShader(vertex_shader, default_frag_shader);
        glDeleteShader(default_frag_shader);

        texture_id = LinkShader(vertex_shader, texture_frag_shader);
        glDeleteShader(vertex_shader);
        glDeleteShader(texture_frag_shader);

        font_id = LinkShader(font_vert_shader, font_frag_shader);
        glDeleteShader(font_vert_shader);
        glDeleteShader(font_frag_shader);
    }

    u32 Shader::CompileShader(const char* name, GLenum type) const {
        i32 success;
        char info_log[512];

        u32 shader      = glCreateShader(type);
        std::string src = Utilities::ReadEntireFile(name);
        const char* s   = src.c_str();
        glShaderSource(shader, 1, &s, NULL);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 512, NULL, info_log);
            std::cerr << "Failed to compile " << name << ": " << info_log
                      << '\n';
        }

        return shader;
    }

    void Shader::SetShader(ShaderType type) {
        switch (type) {
        case ShaderType::SHADER_DEFAULT: {
            current_id = default_id;
            break;
        }
        case ShaderType::SHADER_TEXTURE: {
            current_id = texture_id;
            break;
        }
        case ShaderType::SHADER_FONT: {
            current_id = font_id;
            break;
        }
        }

        Use();
    }

    u32 Shader::LinkShader(u32 shader1, u32 shader2) const {
        u32 shader = glCreateProgram();
        glAttachShader(shader, shader1);
        glAttachShader(shader, shader2);
        glLinkProgram(shader);
        return shader;
    }

    u32 Shader::GetUniformLocation(const char* name) const {
        Assert(name != nullptr,
               "Passed in null pointer for the name of the uniform");
        i32 uniform_location = glGetUniformLocation(current_id, name);

        if (uniform_location < 0) {
            std::cerr << "Tried to get non-existant shader uniform: " << name
                      << '\n';
            return -1;
        }
        return uniform_location;
    }

    void Shader::SetUniform(glm::mat4 data, const char* name) {
        Assert(name != nullptr,
               "Passed in null pointer for the name of the uniform");
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(data));
    }

    void Shader::SetUniform(glm::vec4 data, const char* name) {
        Assert(name != nullptr,
               "Passed in null pointer for the name of the uniform");
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform4fv(uniform_location, 1, glm::value_ptr(data));
    }

    void Shader::SetUniform(glm::vec3 data, const char* name) {
        Assert(name != nullptr,
               "Passed in null pointer for the name of the uniform");
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform3fv(uniform_location, 1, glm::value_ptr(data));
    }

    void Shader::SetUniform(glm::vec2 data, const char* name) {
        Assert(name != nullptr,
               "Passed in null pointer for the name of the uniform");
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform2fv(uniform_location, 1, glm::value_ptr(data));
    }

    void Shader::SetUniform(f32 x, f32 y, f32 z, const char* name) {
        Assert(name != nullptr,
               "Passed in null pointer for the name of the uniform");
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform3f(uniform_location, x, y, z);
    }

    void Shader::Use() const { glUseProgram(current_id); }

    void Shader::SetProjection(glm::vec2 size, glm::vec2 zBounds) {
        Shader::SetUniform(
            glm::ortho(0.0f, size.x, 0.0f, size.y, zBounds.x, zBounds.y),
            "uProjection");
    }
} // namespace ZipLib::Core
