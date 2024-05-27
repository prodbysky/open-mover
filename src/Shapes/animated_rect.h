#pragma once

#include "../Resource/animation.h"
#include "rect.h"

#include <memory>

namespace ZipLib::Shapes {
    // Rectangle that also has a texture to draw
    class AnimatedRect : public Rect {
    private:
        std::shared_ptr<Core::Shader> shader;

    public:
        Animation animation;

    public:
        AnimatedRect() = default;
        AnimatedRect(glm::vec2 pos, f32 w, f32 h,
                     std::shared_ptr<Core::Shader> shader,
                     std::string frame_base_name, u32 frame_count,
                     GLenum texture_filter, GLenum image_type,
                     Core::ResourceManager& manager);
        void Draw();
        void Advance();
        const Core::Texture& GetCurrentFrame();
    };
} // namespace ZipLib::Shapes
