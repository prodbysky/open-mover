#define GLFW_INCLUDE_NONE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include <stb_image.h>
#include <miniaudio.h>

#include "textured_rect.h"
#include "window.h"

#define G -.981
#define GROUND 200

typedef struct {
    textured_rect_t rect;
    vec2s velocity;
    bool grounded;
} player_t;

player_t player_new(vec2s pos) {
    player_t player;
    player.rect = textured_rect_new(pos, 80, 80, "assets/player.png");
    player.velocity = glms_vec2_zero();

    return player;
}

void player_update(player_t* player, window_t window) {
    if (player->rect.pos.y - player->rect.h <= GROUND) {
        player->velocity.y = 0;
        player->grounded = true;
    } else {
        player->velocity.y += G; 
        player->grounded = false;
    }

    if (window_is_key_down(window, GLFW_KEY_SPACE) && player->grounded) {
        player->velocity.y += 20; 
    }

    textured_rect_move(&player->rect, player->velocity);
}

void player_draw(player_t player, window_t* window) {
    textured_rect_draw(player.rect, window);
}

int main() {
    window_t window = window_init(800, 800, "Hello world!");

    if (window.window == NULL) {
        return -1;
    }

    player_t player = player_new((vec2s){.x = 300, .y = 600});

    audio_play(window.audio, "assets/pickupCoin.wav");
    while (!window_should_close(&window)) {
        player_update(&player, window);
        window_clear(24, 24, 24, 255);
        player_draw(player, &window);
        window_swap(&window);
    }

    glfwTerminate();
    return 0;
}
