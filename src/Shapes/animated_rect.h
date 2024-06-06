#pragma once

#include "rect.h"

#include <Resource/animation.h>
#include <Window/renderer.h>

namespace ZipLib::Shapes {
    // Rectangle that also has a texture to draw
    class AnimatedRect : public Rect {

    public:
        AnimatedRect() = default;
        AnimatedRect(glm::vec2 pos, f32 w, f32 h, std::string frame_base_name,
                     u32 frame_count, GLenum texture_filter, GLenum image_type);
        void Draw(Renderer& renderer);
        void Advance();
        const Core::Texture& GetCurrentFrame();

    public:
        Animation animation;

    private:
        DrawCall draw_call;
    };
} // namespace ZipLib::Shapes
