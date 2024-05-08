#include "audio.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <stdlib.h>

namespace StintaEngine::Core {
    Audio::Audio() {
        engine = new ma_engine;
        ma_engine_init(nullptr, engine);

        if (engine == nullptr) {
            std::cerr << "Failed to initialize audio engine!\n";
        }
    }

    void Audio::Play(const char* filename) {
        assert(filename != nullptr && strcmp(filename, "") != 0);
        ma_result result = ma_engine_play_sound(engine, filename, nullptr);
        if (result != MA_SUCCESS) {
            std::cerr << "Failed to play sound: " << filename << '\n';
        }
    }
}
