#pragma once

#include "../Core/vao.h"
#include "../Resource/texture_data.h"
#include "../Window/window.h"
#include "glad/glad.h"
#include "rect.h"

#include <memory>

namespace ZipLib::Shapes {
    // Rectangle that also has a texture to draw
    class TexturedRect {
    public:
        Rect rect;
        Core::Texture texture;

    public:
        TexturedRect();
        // Creates a rectangle with an associated texture that is loaded too
        TexturedRect(glm::vec2 pos, f32 w, f32 h,
                     const ZipLib::Core::TextureData& data,
                     GLenum texture_filter, GLenum image_type);
        void Draw(Core::Shader& shader) const;
        void Move(glm::vec2 move);
        void SetPos(glm::vec2 move);

        void RotateX(f32 degrees);
        void RotateY(f32 degrees);
    };
} // namespace ZipLib::Shapes
