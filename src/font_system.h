#pragma once


#include <memory>
#include <unordered_map>
#include <string>
#include "font.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace StintaEngine::Core {

    // Contains all loaded fonts, exposes a drawing api for fonts in `FontSystem::Draw(...)`
    class FontSystem {
    private: 
        FT_Library freetype;
        std::unique_ptr<Core::VAO> vao;
        Core::VBO vbo;

    public:
        FontSystem();
        // Loads a font from `fontName`
        Font LoadFont(const char* font_name, u16 height = 48);
        void Draw(const Font& font, Core::Shader& shader, std::string text, glm::vec2 pos, float scale, glm::vec3 color);
    };
}
