#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "util.h"

namespace StintaEngine::Core {
    using namespace Types;

    Shader::Shader() {
        const char* vertName = "assets/shaders/quad_vertex.glsl";
        const char* defaultFragName = "assets/shaders/default_quad_fragment.glsl";
        const char* textureFragName = "assets/shaders/texture_quad_fragment.glsl";
        const char* fontVertexName = "assets/shaders/font_vertex.glsl";
        const char* fontFragName = "assets/shaders/font_fragment.glsl";

        u32 vertexShader = CompileShader(vertName, GL_VERTEX_SHADER);
        u32 defaultFragShader = CompileShader(defaultFragName, GL_FRAGMENT_SHADER);
        u32 textureFragShader = CompileShader(textureFragName, GL_FRAGMENT_SHADER);
        u32 fontVertShader = CompileShader(fontVertexName, GL_VERTEX_SHADER);
        u32 fontFragShader = CompileShader(fontFragName, GL_FRAGMENT_SHADER);

        defaultID = glCreateProgram();
        glAttachShader(defaultID, vertexShader);
        glAttachShader(defaultID, defaultFragShader);
        glLinkProgram(defaultID);
        glDeleteShader(defaultFragShader);

        textureID = glCreateProgram();
        glAttachShader(textureID, vertexShader);
        glAttachShader(textureID, textureFragShader);
        glLinkProgram(textureID);
        glDeleteShader(vertexShader);
        glDeleteShader(textureFragShader);

        fontID = glCreateProgram();
        glAttachShader(fontID, fontVertShader);
        glAttachShader(fontID, fontFragShader);
        glLinkProgram(fontID);
        glDeleteShader(fontVertShader);
        glDeleteShader(fontFragShader);
    }

    u32 Shader::CompileShader(const char* name, GLenum type) {
        i32 success;
        char infoLog[512];

        u32 shader = glCreateShader(type);
        std::string src = Utilities::read_entire_file(name);
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
            case ShaderType::SHADER_DEFAULT: {
                    currentID = defaultID;    
                    break;
            }
            case ShaderType::SHADER_TEXTURE: {
                    currentID = textureID;    
                    break;
            }
            case ShaderType::SHADER_FONT: {
                    currentID = fontID;
                    break;
            }
        } 

        Use();
    }
    u32 Shader::GetUniformLocation(const char* name) {
        assert(name != nullptr);
        i32 uniform_location = glGetUniformLocation(currentID, name); 

        if (uniform_location < 0) {
            std::cerr << "Tried to get non-existant shader uniform: " << name << '\n';
            return -1;
        }
        return uniform_location;
    }

    void Shader::SetUniform(glm::mat4 data, const char* name) {
        assert(name != nullptr);
        i32 uniform_location = GetUniformLocation(name);


        Use();
        glUniformMatrix4fv(uniform_location, 1, false, glm::value_ptr(data));
        
    }

    void Shader::SetUniform(glm::vec3 data, const char* name) {
        assert(name != nullptr);
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform3fv(uniform_location, 1, glm::value_ptr(data));
    }


    void Shader::SetUniform(glm::vec2 data, const char* name) {
        assert(name != nullptr);
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform2fv(uniform_location, 1, glm::value_ptr(data));
    }

    void Shader::SetUniform(f32 x, f32 y, f32 z, const char* name) {
        assert(name != nullptr);
        i32 uniform_location = GetUniformLocation(name);

        Use();
        glUniform3f(uniform_location, x, y, z);
    }

    void Shader::Use() {
        glUseProgram(currentID);
    }

    void Shader::SetProjection(glm::vec2 size, glm::vec2 zBounds) {
        Shader::SetUniform(glm::ortho(0.0f, size.x, 0.0f, size.y, zBounds.x, zBounds.y), "uProjection");
    }
}
