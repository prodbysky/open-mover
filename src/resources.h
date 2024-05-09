#pragma once

#include <string>

#include <miniaudio.h>

#include "types.h"

namespace StintaEngine::Core {
    struct TextureData {
        u8* data;
        i32 width, height, nChannels;
        ~TextureData();
    };

    struct Sound {
        ma_decoder decoder;
        Sound(std::string name);
        ~Sound();
    };
}
