#include "../Core/audio.h"

#include "../Utilities/utilities.h"
#include "../include/miniaudio.h"
#include "log.h"

#include <cstdlib>
#include <memory>

namespace ZipLib::Core {
    Audio::Audio() {
        static bool initialized = false;

        if (!initialized) {
            engine = std::make_unique<ma_engine>();
            Assert(ma_engine_init(nullptr, engine.get()) == MA_SUCCESS,
                   "Failed to initialize the engine");

            Log::Info("Succesfully initialized audio system");
            initialized = true;
        }
    }

    void Audio::Play(const char* sound) {
        ma_engine_play_sound(engine.get(), sound, nullptr);
    }
} // namespace ZipLib::Core
