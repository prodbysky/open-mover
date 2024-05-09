#pragma once

#include <unordered_map>

#include <ft2build.h>
#include FT_FREETYPE_H
#include <glm/glm.hpp>

#include "texture.h"
#include "types.h"

namespace StintaEngine {
    // Struct for storing data about a character from a font
    struct Character {
        Core::Texture texture;
        glm::ivec2 size; 
        glm::ivec2 bearing; 
        u32 advance;
    };

    /*
    Contains all cached glyphs of a font, loads a font
    */
    class Font {
    public:
        std::unordered_map<char, Character> chars;
    public:
        Font() = default;
        // Loads a font from `fontName`, and initializes the first 128 ASCII characters with the `height`
        Font(FT_Library freetype, const char* font_name, u16 height);
    };
}
