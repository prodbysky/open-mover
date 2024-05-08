#pragma once
#include "types.h"
#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H

namespace StintaEngine::Core {
    using namespace Types;

    enum class TextureType {
        TEXTURE_GLYPH,
        TEXTURE_IMAGE,
    };

    class Texture {
    private:
        u32 ID;

    public:
        // TODO: Fully featured texture function
        Texture() = default;

        Texture(const char* name, GLenum wrapMode = GL_MIRRORED_REPEAT, 
                         GLenum textureFilter = GL_NEAREST, GLenum imageType = GL_SRGB8,
                         FT_Face face = {}, TextureType type = TextureType::TEXTURE_IMAGE);

        Texture(GLenum wrapMode, GLenum textureFilter, FT_Face face);
        void Bind();
        void Unbind();
    };
}
