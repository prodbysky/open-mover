#pragma once
#include "../Utilities/types.h"

namespace StintaEngine::Core {
    struct TextureData {
        u8* data;
        i32 width, height, nChannels;
        ~TextureData();
    };
}
