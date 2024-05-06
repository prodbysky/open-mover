#pragma once


#include <unordered_map>
#include <string>
#include "font.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"

#include <ft2build.h>
#include FT_FREETYPE_H

class FontSystem {
private: 
    FT_Library freetype;
    std::unordered_map<std::string, Font> fonts;
    VAO vao;
    VBO vbo;

public:
    FontSystem();
    void LoadFont(const char* fontName, u16 height = 48);
    void Draw(std::string font, Shader& shader, std::string text, glm::vec2 pos, float scale, glm::vec3 color);
};
