#include <stb_image.h>
#include <miniaudio.h>

#include <glm/ext/vector_float2.hpp>
#include <glm/gtc/constants.hpp>
#include "font_system.h"
#include "textured_rect.h"
#include "window.h"
#include "rect.h"
#include <GLFW/glfw3.h>

#define G -.981
#define GROUND 200

class Player {
private:
    TexturedRect rect;
    glm::vec2 velocity;
    bool grounded;
public:
    Player(glm::vec2 pos) {
        rect = TexturedRect(pos, 80, 80, "assets/sprites/player.png");
        velocity = glm::zero<glm::vec2>();
    }

    void Update(Window& window) {
        if (rect.pos.y - rect.h <= GROUND) {
            velocity.y = 0;
            grounded = true;
            rect.SetPos(glm::vec2(rect.pos.x, GROUND + 80));
        } else {
            velocity.y += G; 
            grounded = false;
        }
        
        if (window.input.KeyDown(GLFW_KEY_SPACE) && grounded) {
            velocity.y += 20; 
        }

        if (window.input.KeyDown(GLFW_KEY_A)) {
            velocity.x = -10;
        }

        if (window.input.KeyDown(GLFW_KEY_D)) {
            velocity.x = 10;
        }

        velocity.x /= 1.2;
        rect.Move(velocity);
    }

    void Draw(Shader& shader) {
        rect.Draw(shader);
    }
};


int main() {
    Window window(800, 800, "Hello world!");
    window.fontSystem.LoadFont("assets/fonts/arial.ttf", 48);

    if (window.window == nullptr) {
        return -1;
    }

    Player player(glm::vec2(300.0f, 600.0f));
    Rect ground(glm::vec2(0.0f, 200.0f), 800, 80, glm::vec3(1.0f, 1.0f, 1.0f));

    window.audio.Play("assets/sounds/pickupCoin.wav");
    while (!window.ShouldClose()) {
        player.Update(window);
        window.Clear(24, 24, 24, 255);
        player.Draw(*window.shader);
        ground.Draw(*window.shader);
        window.fontSystem.Draw("assets/fonts/arial.ttf", *window.shader, "This is really funny :D", glm::vec2(200, 300), 1, glm::vec3(1, 1, 1));
        window.Swap();
    }
    return 0;
}
