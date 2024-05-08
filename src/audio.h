#pragma once
#include <memory>
#include <miniaudio.h>

namespace StintaEngine::Core {
    class Audio {
    private:
        ma_engine* engine;

    public:
        Audio();
        ~Audio() = default;
        void Play(const char* filename);
    };
}
