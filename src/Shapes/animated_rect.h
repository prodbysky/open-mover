#pragma once

#include "../Resource/animation.h"
#include "rect.h"

namespace ZipLib::Shapes {
    // Rectangle that also has a texture to draw
    class AnimatedRect : public Rect {
    public:
        Animation animation;

    public:
        AnimatedRect() = default;
        AnimatedRect(glm::vec2 pos, f32 w, f32 h, std::string frame_base_name,
                     u32 frame_count, GLenum texture_filter, GLenum image_type,
                     Core::ResourceManager& manager);
        void Draw(Core::Shader& shader);
        void Advance();
        const Core::Texture& GetCurrentFrame();
    };
} // namespace ZipLib::Shapes
