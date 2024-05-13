#include "../Core/audio.h"

#include "../Utilities/utilities.h"
#include "../include/miniaudio.h"

#include <cstdlib>

namespace ZipLib::Core {
    Audio::Audio() {
        engine = (ma_engine*) malloc(sizeof(ma_engine));
        Assert(ma_engine_init(nullptr, engine) == MA_SUCCESS,
               "Failed to initialize the engine");
    }
    Audio::~Audio() {}

    void Audio::Play(const char* sound) {
        ma_engine_play_sound(engine, sound, nullptr);
    }
} // namespace ZipLib::Core
