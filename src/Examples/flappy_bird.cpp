#include "../Window/window.h"
#include "../Shapes/textured_rect.h"
#include "../Utilities/util.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#define G -25

using namespace StintaEngine;

class Bird {
private:
    Shapes::TexturedRect rect; 
    f64 velocity;
    f32 jump_power;
public:
    Bird(glm::vec2 pos, f32 power, Core::ResourceManager& resource_manager) {
        rect = Shapes::TexturedRect(pos, 64, 64, resource_manager.LoadTexture("assets/sprites/orange.png"), GL_NEAREST, GL_RGBA8);
        velocity = 0.0;
        jump_power = power;
    }

    void Update(const Core::Input &input, f64 delta) {
        if (input.KeyDown(GLFW_KEY_SPACE)) {
            velocity = jump_power * delta;  
        } else {
            velocity += G * delta;
        }

        rect.Move(glm::vec2(0, velocity));
    }

    void Draw(Core::Shader &shader) {
        rect.Draw(shader);
    }
};

class Pipe {
private:
    Shapes::TexturedRect lower_pipe; 
    Shapes::TexturedRect upper_pipe; 
public:
    Pipe(glm::vec2 pos, Core::ResourceManager& resource_manager) {
        lower_pipe = Shapes::TexturedRect(pos, 140, 1400, resource_manager.LoadTexture("assets/sprites/pipe.png"), GL_NEAREST, GL_RGBA8);
        upper_pipe = Shapes::TexturedRect(glm::vec2(pos.x, pos.y + 180 + 1400), 140, 1400, resource_manager.LoadTexture("assets/sprites/pipe_flipped.png"), GL_NEAREST, GL_RGBA8);
    }

    void Update(f64 delta) {
        lower_pipe.Move(glm::vec2(-300 * delta, 0));
        upper_pipe.Move(glm::vec2(-300 * delta, 0));

        if (lower_pipe.pos.x < -140) {
            lower_pipe.Move(glm::vec2(1000, Utilities::RandomFloat(-100, 100)));
            upper_pipe.Move(glm::vec2(1000, Utilities::RandomFloat(-100, 100)));
        }
    }

    void Draw(Core::Shader& shader) {
        lower_pipe.Draw(shader);
        upper_pipe.Draw(shader);
    }
};

i32 main() {
    Window window(800, 800, "Flappy bird", true);
    Shapes::TexturedRect background(glm::vec2(0, 800), 800, 800, window.resource_manager.LoadTexture("assets/sprites/bg.png"), GL_LINEAR, GL_RGBA8);
    Bird bird(glm::vec2(200, 300), 500, window.resource_manager);
    Pipe pipe(glm::vec2(400, 200), window.resource_manager);

    while (!window.ShouldClose()) {
        bird.Update(window.input, window.GetDeltaTime());
        pipe.Update(window.GetDeltaTime());
        window.Clear(24, 24, 24, 255);
        background.Draw(*window.shader);
        bird.Draw(*window.shader);
        pipe.Draw(*window.shader);
        window.Swap();
    }
}
