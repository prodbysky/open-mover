#pragma once
#include <miniaudio.h>

typedef ma_engine audio_t;

audio_t* audio_new();

void audio_play(audio_t* audio, const char* filename);
