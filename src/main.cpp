#include <cglm/cglm.h>

#include <stb_image.h>
#include <miniaudio.h>

#include "textured_rect.h"
#include <GLFW/glfw3.h>
#include "window.h"

#define G -.981
#define GROUND 200

class Player {
private:
    TexturedRect rect;
    vec2s velocity;
    bool grounded;

public:
    Player(vec2s pos) {
        rect = TexturedRect(pos, 80, 80, "assets/player.png");
        velocity = glms_vec2_zero();
    }

    void Update(Window& window) {
        if (rect.pos.y - rect.h <= GROUND) {
            velocity.y = 0;
            grounded = true;
        } else {
            velocity.y += G; 
            grounded = false;
        }
        
        if (window.input.KeyDown(GLFW_KEY_SPACE) && grounded) {
            velocity.y += 20; 
        }
        rect.Move(velocity);
    }

    void Draw(Shader& shader) {
        rect.Draw(shader);
    }
};


int main() {
    Window window(800, 800, "Hello world!");

    if (window.window == nullptr) {
        return -1;
    }

    Player player((vec2s){.x = 300, .y = 600});

    window.audio.Play("assets/pickupCoin.wav");
    while (!window.ShouldClose()) {
        player.Update(window);
        window.Clear(24, 24, 24, 255);
        player.Draw(*window.shader);
        window.Swap();
    }
    return 0;
}
