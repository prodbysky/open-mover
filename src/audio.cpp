#include "audio.h"
#include <stdlib.h>

Audio::Audio() {
    engine = (ma_engine*)malloc(sizeof(ma_engine));
    ma_engine_init(NULL, engine);

    if (engine == nullptr) {
    }
}

void Audio::Play(const char* filename) {
    ma_engine_play_sound(engine, filename, NULL);
}
