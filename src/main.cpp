#include <stb_image.h>
#include <miniaudio.h>

#include <glm/ext/vector_float2.hpp>
#include <glm/gtc/constants.hpp>
#include "glad/glad.h"
#include "rect.h"
#include "textured_rect.h"
#include "window.h"
#include <GLFW/glfw3.h>
#include <vector>

#define G -.25

class Fruit {
public:
    TexturedRect rect;
    glm::vec2 velocity;
public:
    Fruit(glm::vec2 pos) {
        rect = TexturedRect(pos, 64, 64, "assets/sprites/orange.png", GL_LINEAR, GL_RGBA16);
        velocity = glm::zero<glm::vec2>();
    }
    void Update() {
        velocity.y += G; 
        rect.Move(velocity);
        if (rect.pos.y < 0) {
            rect.SetPos(glm::vec2(rect.pos.x, 964));
            velocity.y = 0;
        }
        
    }
    void Draw(Window& window) {
        rect.Draw(*window.shader);
    }
};

int main() {
    Window window(800, 800, "Hello world!");
    
    std::vector<Fruit> fruits;
    Rect ground(glm::vec2(0, 200), 800, 64, glm::vec3(1, 1, 1));

    for (u64 i = 0; i < 1; i++) {
        fruits.push_back(Fruit(glm::vec2(400 + i, 400 + i)));
    }

    if (window.window == nullptr) {
        return -1;
    }

    while (!window.ShouldClose()) {
        glm::vec2 mPos = window.input.GetMousePos();
        for (u64 i = 0; i < fruits.size(); i++) {
            Fruit& f = fruits[0];

            if (window.input.MouseKeyDown(GLFW_MOUSE_BUTTON_LEFT)          &&
               (mPos.x > f.rect.pos.x && mPos.x < f.rect.pos.x + f.rect.w) && 
               (mPos.y < f.rect.pos.y && mPos.x > f.rect.pos.y - f.rect.h)) {
                fruits.erase(fruits.begin() + i);
            }
        }

        for (Fruit& f : fruits) {
            f.Update();
        }
        window.Clear(24, 24, 24, 255);
        for (Fruit& f : fruits) {
            f.Draw(window);
        }
        ground.Draw(*window.shader);
        window.Swap();
    }
    return 0;
}
