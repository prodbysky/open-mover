#pragma once
#include <memory>
#include <miniaudio.h>

namespace StintaEngine::Core {

    // Manages miniaudio and plays audio on demand
    class Audio {
    private:
        ma_engine* engine;

    public:
        Audio();
        ~Audio() = default;
        // Loads a sound file from `file_name` and instantly plays it
        void Play(const char* file_name) const;
    };
}
