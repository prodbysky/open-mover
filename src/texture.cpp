#include "texture.h"
#include <glad/glad.h>
#include <iostream>
#include <stb_image.h>

Texture::Texture(const char* name, GLenum wrapMode, 
                 GLenum textureFilter, GLenum mipmapMinFilter, 
                 GLenum mipmapMagFilter, GLenum imageType) {
    glCreateTextures(GL_TEXTURE_2D, 1, &ID);

    glTextureParameteri(ID, GL_TEXTURE_WRAP_S, wrapMode);
    glTextureParameteri(ID, GL_TEXTURE_WRAP_T, wrapMode);
    glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, textureFilter);
    glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, textureFilter);

    glTextureParameteri(ID, GL_TEXTURE_MIN_FILTER, mipmapMinFilter);
    glTextureParameteri(ID, GL_TEXTURE_MAG_FILTER, mipmapMagFilter);

    i32 width, height, nChannels;
    stbi_set_flip_vertically_on_load(1);
    u8* data = stbi_load(name, &width, &height, &nChannels, 0);

    if (data) {
        glTextureStorage2D(ID, 1, imageType, width, height);
        glTextureSubImage2D(ID, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateTextureMipmap(ID);
    } else {
        std::cerr << "Failed to load texture: " << name << '\n';
    }
    stbi_image_free(data);
}

void Texture::Bind() {
    glBindTextureUnit(0, ID);
}

void Texture::Unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
