#include "audio.h"
#include <iostream>
#include <stdlib.h>

Audio::Audio() {
    engine = new ma_engine;
    ma_engine_init(nullptr, engine);

    if (engine == nullptr) {
        std::cerr << "Failed to initialize audio engine!\n";
    }
}

void Audio::Play(const char* filename) {
    ma_engine_play_sound(engine, filename, nullptr);
}
