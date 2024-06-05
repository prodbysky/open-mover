#include "animation.h"

#include "../Core/log.h"
#include "../Utilities/assert.h"

namespace ZipLib {
    Animation::Animation(std::string sprite_base_name, u32 frame_count,
                         GLenum wrap, GLenum filter, GLenum type,
                         Core::ResourceManager& manager) {
        current_frame = 0;

        for (u32 i = 0; i < frame_count; i++) {
            std::string name =
                sprite_base_name + "_" + std::to_string(i) + ".png";
            frames.push_back(Core::Texture(manager.LoadTexture(name), wrap,
                                           filter, type, {},
                                           Core::TextureType::TEXTURE_IMAGE));
        }
        Log::Info("Succesfully loaded animation:", sprite_base_name);
    }

    void Animation::Advance() {
        current_frame = (current_frame + 1) % frames.size();
    }

    void Animation::SetCurrentFrame(u32 frame) {
        Assert(frame < frames.size(),
               "Invalid frame to set to (frame >= frames.size())");
        current_frame = frame;
    }

    Core::Texture& Animation::GetCurrentFrame() {
        return frames.at(current_frame);
    }

} // namespace ZipLib
