#pragma once

#include <memory>

#include "texture.h"
#include "glad/glad.h"
#include "resource_manager.h"
#include "texture.h"
#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "window.h"
#include "types.h"

namespace StintaEngine {
    using namespace Types;

    // Rectangle that also has a texture to draw
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
        TexturedRect() = default;
        // Creates a rectangle with an associated texture that is loaded too
        TexturedRect(glm::vec2 pos, f32 w, f32 h, const Core::TextureData& data, GLenum texture_filter, GLenum image_type);
        void Draw(Core::Shader& shader) const;
        void Move(glm::vec2 move);
        void SetPos(glm::vec2 move);
    };
}
