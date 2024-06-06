#include <Core/texture.h>
#include <Resource/texture_data.h>
#include <cstring>
#include <glad/glad.h>
#include <stb_image.h>

namespace ZipLib::Core {
    Texture::Texture(const TextureData& data, GLenum wrap_mode,
                     GLenum texture_filter, GLenum image_type, FT_Face face,
                     TextureType type) {
        Setup(wrap_mode, texture_filter);
        if (type == TextureType::TEXTURE_IMAGE) {
            WriteImage(data, image_type);
            return;
        }

        WriteGlyph(face);
    }

    Texture::Texture(GLenum wrap_mode, GLenum texture_filter, FT_Face face) :
        Texture({}, wrap_mode, texture_filter, GL_SRGB8, face,
                TextureType::TEXTURE_GLYPH) {}

    Texture::Texture(const TextureData& data, GLenum wrap_mode,
                     GLenum texture_filter, GLenum image_type) :
        Texture(data, wrap_mode, texture_filter, image_type, {},
                TextureType::TEXTURE_IMAGE) {}

    void Texture::Bind() const { glBindTextureUnit(0, ID); }

    void Texture::Unbind() const { glBindTextureUnit(0, 0); }

    void Texture::Setup(GLenum wrap_mode, GLenum texture_filter) {
        glCreateTextures(GL_TEXTURE_2D, 1, &ID);

        glTextureParameteri(ID, GL_TEXTURE_WRAP_S, wrap_mode);
        glTextureParameteri(ID, GL_TEXTURE_WRAP_T, wrap_mode);
        glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, texture_filter);
        glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, texture_filter);
    }

    void Texture::WriteImage(const TextureData& data, GLenum image_type) {
        glTextureStorage2D(ID, 1, image_type, data.width, data.height);
        glTextureSubImage2D(ID, 0, 0, 0, data.width, data.height, GL_RGBA,
                            GL_UNSIGNED_BYTE, data.data);
        glGenerateTextureMipmap(ID);
    }

    void Texture::WriteGlyph(FT_Face face) {
        glTextureStorage2D(ID, 1, GL_R8, face->glyph->bitmap.width,
                           face->glyph->bitmap.rows);
        glTextureSubImage2D(ID, 0, 0, 0, face->glyph->bitmap.width,
                            face->glyph->bitmap.rows, GL_RED, GL_UNSIGNED_BYTE,
                            face->glyph->bitmap.buffer);
    }
} // namespace ZipLib::Core
