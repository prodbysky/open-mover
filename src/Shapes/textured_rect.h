#pragma once

#include "../Core/vao.h"
#include "../Resource/texture_data.h"
#include "../Window/window.h"
#include "glad/glad.h"
#include "rect.h"

#include <memory>

namespace ZipLib::Shapes {
    // Rectangle that also has a texture to draw
    class TexturedRect : public Rect {
    public:
        Core::Texture texture;

    public:
        TexturedRect();
        // Creates a rectangle with an associated texture that is loaded too
        TexturedRect(glm::vec2 pos, f32 w, f32 h,
                     const ZipLib::Core::TextureData& data,
                     GLenum texture_filter, GLenum image_type);
        void Draw(Core::Shader& shader) const;
    };
} // namespace ZipLib::Shapes
