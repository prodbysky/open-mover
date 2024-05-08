#pragma once

#include <memory>

#include "glad/glad.h"
#include "texture.h"
#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "window.h"

#include "types.h"

namespace StintaEngine {
    using namespace Types;

    class TexturedRect {
    public:
        Core::VAO vao;
        Core::VBO vbo;
        Core::EBO ebo;
        glm::mat4 model;
        Core::Texture texture;
        glm::vec2 pos;
        f32 w, h;
    public:
        // TODO: again options for the textures
        TexturedRect() = default;
        TexturedRect(glm::vec2 pos, f32 w, f32 h, const char* textureName, GLenum textureFilter = GL_NEAREST, GLenum imageType = GL_SRGB8);
        void Draw(Core::Shader& shader);
        void Move(glm::vec2 move);
        void SetPos(glm::vec2 move);
    };
}
