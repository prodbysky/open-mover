#pragma once

#include "glm/ext/vector_int2.hpp"
#include "texture.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glad/glad.h>

#include <glm/glm.hpp>

#include "types.h"

struct Character {
    Texture texture;
    glm::ivec2 size; 
    glm::ivec2 bearing; 
    u32 advance;
};

class Font {
public:
    std::unordered_map<char, Character> chars;

public:
    Font() = default;
    Font(FT_Library& freetype, const char* fontName, u16 height);
};
