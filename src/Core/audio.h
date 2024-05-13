#pragma once
#include <miniaudio.h>

namespace ZipLib::Core {
    // Manages miniaudio and plays audio on demand
    class Audio {
    public:
        ma_engine* engine;

    public:
        Audio();
        ~Audio();
        void Play(const char* sound);
    };
} // namespace ZipLib::Core
