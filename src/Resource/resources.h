#pragma once

#include "../Core/texture.h"
#include "../Utilities/types.h"
#include "freetype/freetype.h"
#include "glm/ext/vector_int2.hpp"

#include <miniaudio.h>
#include <string>
#include <unordered_map>

namespace ZipLib {
    struct Sound {
        ma_decoder decoder;
        Sound(std::string name);
        ~Sound();
    };

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
        // Loads a font from `fontName`, and initializes the first 128 ASCII
        // characters with the `height`
        Font(FT_Library freetype, const char *font_name, u16 height);
    };
} // namespace ZipLib
