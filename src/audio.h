#pragma once
#include <miniaudio.h>

#include "resources.h"

namespace StintaEngine::Core {
    // Manages miniaudio and plays audio on demand
    class Audio {
    private:
        ma_device_config device_config;
        ma_device device;
    private:
        static void DataCallback(ma_device* device, void* output, const void* input, u32 frame_count);
    public:
        Audio();
        ~Audio() = default;
        void Play(const Sound& sound);
    };
}
