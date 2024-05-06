#include "font_system.h"
#include "glad/glad.h"
#include <iostream>
#include <memory>

FontSystem::FontSystem() : vao(nullptr) {
    if (FT_Init_FreeType(&freetype)) {
        std::cerr << "Failed to initialize Freetype library\n";
    }

    vao = std::make_unique<VAO>();
    vbo = VBO(NULL, 24, GL_DYNAMIC_DRAW); // Reserve space for vertices

    vao->AddAttribute(4, GL_FLOAT);
    vao->LinkVBO(vbo);
}

void FontSystem::LoadFont(const char* fontName, u16 height) {
    fonts[std::string(fontName)] = Font(freetype, fontName, height);
}

void FontSystem::Draw(std::string font, Shader& shader, std::string text, glm::vec2 pos, float scale, glm::vec3 color) {
    shader.SetShader(SHADER_FONT);
    
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

        // update content of VBO memory
        glNamedBufferSubData(vbo.ID, 0, 24 * sizeof(f32), vertices);


        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        pos.x += (ch.advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
    }
    
}
