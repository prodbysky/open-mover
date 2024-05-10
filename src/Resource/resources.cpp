#include "stb_image.h"

#include "../Resource/resources.h"
#include "../Utilities/assert.h"

namespace StintaEngine::Core {
    TextureData::~TextureData() {};

    Sound::Sound(std::string name) {
        Assert(ma_decoder_init_file(name.c_str(), nullptr, &decoder) == MA_SUCCESS, "Failed to load file");
    }

    Sound::~Sound() {};
}
