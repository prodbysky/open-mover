#pragma once

#include <ft2build.h>
#include <glad/glad.h>
#include FT_FREETYPE_H

#include "../Resource/texture_data.h"
#include "../Utilities/types.h"

namespace ZipLib::Core {
    // All texture types
    enum class TextureType {
        TEXTURE_GLYPH,
        TEXTURE_IMAGE,
    };

    // Loads and manages a texture
    class Texture {
    private:
        u32 ID;

    public:
        Texture() = default;

        // Loads a texture or a glyph, based on passed in `type`
        Texture(const TextureData& data, GLenum wrap_mode = GL_MIRRORED_REPEAT,
                GLenum texture_filter = GL_NEAREST,
                GLenum image_type = GL_SRGB8, FT_Face face = {},
                TextureType type = TextureType::TEXTURE_IMAGE);
        // Loads a glyph from a font
        Texture(GLenum wrap_mode, GLenum texture_filter, FT_Face face);
        Texture(const TextureData& data, GLenum wrap_mode,
                GLenum texture_filter, GLenum image_type);
        void Bind() const;
        void Unbind() const;
    };
} // namespace ZipLib::Core
