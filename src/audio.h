#pragma once
#include <memory>
#include <miniaudio.h>

class Audio {
private:
    std::unique_ptr<ma_engine> engine;

public:
    Audio();
    void Play(const char* filename);
};
