#pragma once
#include "types.h"
#include <glad/glad.h>

typedef u32 texture_t; 
class Texture {
private:
    u32 ID;

public:
    // TODO: Fully featured texture function
    Texture() = default;
    Texture(const char* name, GLenum wrapMode = GL_MIRRORED_REPEAT, 
                     GLenum textureFilter = GL_NEAREST, GLenum mipmapMinFilter = GL_LINEAR_MIPMAP_NEAREST, 
                     GLenum mipmapMagFilter = GL_NEAREST, GLenum imageType = GL_SRGB8);
    void Bind();
    void Unbind();
};
