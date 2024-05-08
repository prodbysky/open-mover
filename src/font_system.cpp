#include "font_system.h"
#include "assert.h"
#include "glad/glad.h"
#include "shader.h"
#include <cassert>
#include <iostream>
#include <memory>

namespace StintaEngine::Core {
    FontSystem::FontSystem() : vao(nullptr) {
        if (FT_Init_FreeType(&freetype)) {
            std::cerr << "Failed to initialize Freetype library\n";
        }

        vao = std::make_unique<Core::VAO>();
        vbo = Core::VBO(NULL, 24, GL_DYNAMIC_DRAW); // Reserve space for vertices

        vao->AddAttribute(4, GL_FLOAT);
        vao->LinkVBO(vbo);
    }

    void FontSystem::LoadFont(const char* fontName, u16 height) {
        Assert(fontName != nullptr, "Passed in null pointer");
        Assert(height >= 0, "Non-positive font height passed in");
        fonts[std::string(fontName)] = Font(freetype, fontName, height);
    }

    void FontSystem::Draw(std::string font, Core::Shader& shader, std::string text, glm::vec2 pos, float scale, glm::vec3 color) {
        Assert(font != std::string(""), "Passed in nothing for the font name");
        shader.SetShader(Core::ShaderType::SHADER_FONT);
        
        shader.SetUniform(color.r, color.g, color.b, "uColor");
        vao->Bind();

        for (const char& c : text) {
            Character ch = fonts[font].chars[c];

            float xpos = pos.x + ch.bearing.x * scale;
            float ypos = pos.y - (ch.size.y - ch.bearing.y) * scale;

            float w = ch.size.x * scale;
            float h = ch.size.y * scale;

            float vertices[24] = {
                 xpos,     ypos + h,   0.0f, 0.0f,            
                 xpos,     ypos,       0.0f, 1.0f,
                 xpos + w, ypos,       1.0f, 1.0f,
                 xpos,     ypos + h,   0.0f, 0.0f,
                 xpos + w, ypos,       1.0f, 1.0f,
                 xpos + w, ypos + h,   1.0f, 0.0f            
            };
            vao->Bind();
            ch.texture.Bind();

            glNamedBufferSubData(vbo.ID, 0, 24 * sizeof(f32), vertices);

            glDrawArrays(GL_TRIANGLES, 0, 6);

            pos.x += (ch.advance >> 6) * scale;
        }
    }
}
