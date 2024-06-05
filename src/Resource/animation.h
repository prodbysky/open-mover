#pragma once

#include "../Resource/resource_manager.h"

#include <vector>

namespace ZipLib {

    class Animation {
    private:
        std::vector<Core::Texture> frames;
        u32 current_frame;

    public:
        Animation() = default;
        Animation(std::string sprite_base_name, u32 frame_count, GLenum wrap,
                  GLenum filter, GLenum type, Core::ResourceManager& manager);
        void Advance();
        void SetCurrentFrame(u32 frame);
        Core::Texture& GetCurrentFrame();
    };
} // namespace ZipLib
