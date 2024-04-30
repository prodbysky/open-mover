#include "texture.h"
#include <glad/glad.h>
#include <stb_image.h>

texture_t texture_new(const char* name) {
    texture_t texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    i32 width, height, nChannels;
    stbi_set_flip_vertically_on_load(1);
    u8* data = stbi_load(name, &width, &height, &nChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); 
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        fprintf(stderr, "Failed to load texture: %s", name);
    }
    stbi_image_free(data);
    return texture;
}

void texture_bind(texture_t texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
}

void texture_unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
