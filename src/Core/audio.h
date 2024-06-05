#pragma once

#include <memory>
#include <miniaudio.h>

namespace ZipLib::Core {
    // Manages miniaudio and plays audio on demand
    class Audio {

    public:
        Audio();
        ~Audio() = default;
        void Play(const char* sound);

    private:
        inline static std::unique_ptr<ma_engine> engine;
    };
} // namespace ZipLib::Core
