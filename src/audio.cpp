#include "audio.h"
#include <iostream>
#include <memory>

Audio::Audio() {
    engine = std::make_unique<ma_engine>();
    ma_engine_init(NULL, engine.get());

    if (engine == nullptr) {
        std::cerr << "Failed to initialize audio engine!" << '\n'; 
    }
}

void Audio::Play(const char* filename) {
    ma_engine_play_sound(engine.get(), filename, NULL);
}
