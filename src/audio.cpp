#include "audio.h"
#include "assert.h"
#include <iostream>
#include <stdlib.h>

namespace StintaEngine::Core {
    Audio::Audio() {
        engine = new ma_engine;
        ma_engine_init(nullptr, engine);

        Assert(engine != nullptr, "Failed to initialize audio engine!");
    }

    void Audio::Play(const char* file_name) const {
        Assert(file_name != nullptr, "Passed in null pointer");
        ma_result result = ma_engine_play_sound(engine, file_name, nullptr);
        if (result != MA_SUCCESS) {
            std::cerr << "Failed to play sound: " << file_name << '\n';
        }
    }
}
