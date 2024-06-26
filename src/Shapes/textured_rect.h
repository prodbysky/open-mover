#pragma once

#include "rect.h"

#include <Window/renderer.h>

namespace ZipLib::Shapes {
    // Rectangle that also has a texture to draw
    class TexturedRect : public Rect {
    public:
        TexturedRect();
        // Creates a rectangle with an associated texture that is loaded too
        TexturedRect(glm::vec2 pos, f32 w, f32 h,
                     const ZipLib::Core::TextureData& data,
                     GLenum texture_filter, GLenum image_type);
        void Draw(Renderer& renderer);

    public:
        Core::Texture texture;

    private:
        DrawCall draw_call;
    };
} // namespace ZipLib::Shapes
