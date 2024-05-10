#include <cstring>

#include "../Core/texture.h"
#include "../Resource/resources.h"
#include <glad/glad.h>
#include <stb_image.h>


namespace StintaEngine::Core {
    Texture::Texture(TextureData data, GLenum wrap_mode, 
                     GLenum texture_filter, GLenum image_type,
                     FT_Face face, TextureType type) {

        glCreateTextures(GL_TEXTURE_2D, 1, &ID);

        glTextureParameteri(ID, GL_TEXTURE_WRAP_S, wrap_mode);
        glTextureParameteri(ID, GL_TEXTURE_WRAP_T, wrap_mode);
        glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, texture_filter);
        glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, texture_filter);

        if (type == TextureType::TEXTURE_IMAGE) {
            glTextureStorage2D(ID, 1, image_type, data.width, data.height);
            glTextureSubImage2D(ID, 0, 0, 0, data.width, data.height, GL_RGBA, GL_UNSIGNED_BYTE, data.data);
            glGenerateTextureMipmap(ID);
        } else {
            glTextureStorage2D(ID, 1, GL_R8, face->glyph->bitmap.width, face->glyph->bitmap.rows);
            glTextureSubImage2D(ID, 0, 0, 0, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
        }
    }

    Texture::Texture(GLenum wrap_mode, GLenum texture_filter, FT_Face face)
        : Texture({}, wrap_mode, texture_filter, GL_SRGB8, face, TextureType::TEXTURE_GLYPH) {};

    void Texture::Bind() const {
        glBindTextureUnit(0, ID);
    }

    void Texture::Unbind() const {
        glBindTextureUnit(0, 0);
    }
}
