#pragma once

#include <memory>

#include "../Core/texture.h"
#include "glad/glad.h"
#include "../Resource/resource_manager.h"
#include "../Core/texture.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"
#include "../Core/ebo.h"
#include "../Window/window.h"
#include "../Utilities/types.h"

namespace StintaEngine::Shapes {
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
