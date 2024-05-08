#include "texture.h"
#include <cassert>
#include <cstring>
#include <glad/glad.h>
#include <iostream>
#include <stb_image.h>

Texture::Texture(const char* name, GLenum wrapMode, 
                 GLenum textureFilter, GLenum imageType,
                 FT_Face face, TextureType type) {

    assert(name != nullptr);

    glCreateTextures(GL_TEXTURE_2D, 1, &ID);

    glTextureParameteri(ID, GL_TEXTURE_WRAP_S, wrapMode);
    glTextureParameteri(ID, GL_TEXTURE_WRAP_T, wrapMode);
    glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, textureFilter);
    glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, textureFilter);

    if (type == TEXTURE_IMAGE) {
        i32 width, height, nChannels;
        stbi_set_flip_vertically_on_load(1);
        u8* data = stbi_load(name, &width, &height, &nChannels, 0);

        if (data) {
            glTextureStorage2D(ID, 1, imageType, width, height);
            glTextureSubImage2D(ID, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateTextureMipmap(ID);
        } else {
            std::cerr << "Failed to load texture: " << name << '\n';
        }
        stbi_image_free(data);
    } else {
        glTextureStorage2D(ID, 1, GL_R8, face->glyph->bitmap.width, face->glyph->bitmap.rows);
        glTextureSubImage2D(ID, 0, 0, 0, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
    }
}

Texture::Texture(GLenum wrapMode, GLenum textureFilter, FT_Face face)
    : Texture("", wrapMode, textureFilter, GL_SRGB8, face, TEXTURE_GLYPH) {};

void Texture::Bind() {
    glBindTextureUnit(0, ID);
}

void Texture::Unbind() {
    glBindTextureUnit(0, 0);
}
