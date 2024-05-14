#include "../Resource/resources.h"

#include "../Core/texture.h"
#include "../Utilities/assert.h"
#include "glad/glad.h"
#include "stb_image.h"

#include <iostream>

namespace ZipLib {
    Font::Font(FT_Library freetype, const char* font_name, u16 height) {
        Assert(font_name != nullptr, "Passed in null pointer");
        FT_Face face;
        if (FT_New_Face(freetype, font_name, 0, &face)) {
            std::cerr << "Failed to load font: " << font_name << '\n';
        }
        std::cerr << "Loaded font " << font_name << '\n';

        FT_Set_Pixel_Sizes(face, 0, height);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        for (i64 c = 0; c < 128; c++) {
            if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
                std::cerr << "Failed to load glyph: " << char(c) << '\n';
                continue;
            }
            Character character = {
                Core::Texture(GL_CLAMP_TO_EDGE, GL_LINEAR, face),

                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                u32(face->glyph->advance.x)};
            chars[c] = character;
        }

        FT_Done_Face(face);
    }

} // namespace ZipLib
