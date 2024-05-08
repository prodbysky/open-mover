#include "font.h"
#include "glad/glad.h"
#include "texture.h"
#include <cassert>
#include <iostream>

Font::Font(FT_Library& freetype, const char* fontName, u16 height) {
    FT_Face face;
    if (FT_New_Face(freetype, fontName, 0, &face)) {
        std::cerr << "Failed to load font: " << fontName << '\n';
    }
    std::cerr << "Loaded font " << fontName << '\n';

    FT_Set_Pixel_Sizes(face, 0, height);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 

    for (i64 c = 0; c < 128; c++ ) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            std::cerr << "Failed to load glyph: " << char(c) << '\n';
            continue;
        }

        u32 ID;
        glCreateTextures(GL_TEXTURE_2D, 1, &ID);

        glTextureParameteri(ID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTextureParameteri(ID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTextureStorage2D(ID, 1, GL_R8, face->glyph->bitmap.width, face->glyph->bitmap.rows);
        glTextureSubImage2D(ID, 0, 0, 0, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
        Character character = {
            Texture(GL_CLAMP_TO_EDGE, GL_LINEAR, face),
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            u32(face->glyph->advance.x)
        };

        chars[c] = character;
    }

    FT_Done_Face(face);
}
