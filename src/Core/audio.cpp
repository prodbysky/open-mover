#include <iostream>
#include "../Core/audio.h"
#include "../Resource/resources.h"

namespace StintaEngine::Core {
    Audio::Audio() {};

    void Audio::Play(const Sound& sound) {
        device_config = ma_device_config_init(ma_device_type_playback);
        device_config.playback.format   = sound.decoder.outputFormat;
        device_config.playback.channels = sound.decoder.outputChannels;
        device_config.sampleRate        = sound.decoder.outputSampleRate;
        device_config.dataCallback      = DataCallback;
        device_config.pUserData         = (void*)&sound.decoder;

        ma_result result = ma_device_init(nullptr, &device_config, &device);

        if (result != MA_SUCCESS) {
            std::cerr << "Failed to open playback device \n";
            return;
        }

        if (ma_device_start(&device) != MA_SUCCESS) {
            std::cerr << "Failed to start playback device.\n";
            ma_device_uninit(&device);
        }
    }
    void Audio::DataCallback(ma_device* device, void* output, const void* input, u32 frame_count) {
        ma_decoder* decoder = (ma_decoder*)device->pUserData;
        if (decoder == nullptr) {
            return;
        }

        ma_decoder_read_pcm_frames(decoder, output, frame_count, nullptr);

        (void) input;
    }
}
