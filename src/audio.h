#pragma once
#include <memory>
#include <miniaudio.h>

class Audio {
private:
    ma_engine* engine;

public:
    Audio();
    ~Audio() = default;
    void Play(const char* filename);
};
