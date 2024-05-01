#define GLFW_INCLUDE_NONE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <stb_image.h>
#include <miniaudio.h>

#include "rect.h"
#include "window.h"
#include "textured_rect.h"
#include "audio.h"


int main() {
    window_t window = window_init(800, 800, "Hello world!");

    if (window.window == NULL) {
        return -1;
    }

    rect_t rect = rect_new((vec2s){.x = 200, .y = 600}, 80, 80, (vec3s){.r = 1, .g = 1, .b = 1});
    textured_rect_t tRect = textured_rect_new((vec2s){.x = 300, .y = 600}, 80, 80, "assets/player.png");

    audio_play(window.audio, "assets/pickupCoin.wav");
    while (!window_should_close(&window)) {
        window_clear(24, 24, 24, 255);
        rect_draw(rect, &window);
        textured_rect_draw(tRect, &window);
        window_swap(&window);
    }


    glfwTerminate();
    return 0;
}
