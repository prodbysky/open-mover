#include "audio.h"
#include <stdlib.h>
#include <stdio.h>

audio_t* audio_new() {
    ma_result result;
    audio_t* engine = (audio_t*)malloc(sizeof(audio_t));

    result = ma_engine_init(NULL, engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine\n");
    }

    return engine;
}

void audio_play(audio_t* audio, const char* filename) {
    ma_engine_play_sound(audio, filename, NULL);
}
