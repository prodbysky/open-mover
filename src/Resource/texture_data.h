#pragma once
#include "../Utilities/types.h"

namespace ZipLib::Core {
    struct TextureData {
        u8* data;
        i32 width, height, nChannels;
        ~TextureData();
    };
}
