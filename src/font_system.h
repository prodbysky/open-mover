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
    class FontSystem {
    private: 
        FT_Library freetype;
        std::unordered_map<std::string, Font> fonts;
        std::unique_ptr<Core::VAO> vao;
        Core::VBO vbo;

    public:
        FontSystem();
        void LoadFont(const char* fontName, u16 height = 48);
        void Draw(std::string font, Core::Shader& shader, std::string text, glm::vec2 pos, float scale, glm::vec3 color);
    };
}
