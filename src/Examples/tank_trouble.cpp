#include "../Core/ZipLib.h"
#include "../Shapes/shapes.h"
#include "../Window/timer.h"
#include "../Window/window.h"
#include "glm/detail/type_vec2.hpp"
#include "glm/ext/vector_float2.hpp"

enum class Direction {
    Left = 0,
    Right,
    Up,
    Down,
};

class Bullet {
public:
    Bullet() : rect({-1, -1}, 16, 16) {}
    Bullet(glm::vec2 position, Direction dir) : rect(position, 16, 16) {
        switch (dir) {
        case Direction::Left:
            velocity = {-Speed, 0};
            break;
        case Direction::Right:
            velocity = {Speed, 0};
            break;

        case Direction::Up:
            velocity = {0, Speed};
            break;

        case Direction::Down:
            velocity = {0, -Speed};
            break;
        }

        timer = ZipLib::Timer(TTL);
        timer.Start();
    }

    void Update(f64 delta) {
        if (timer.Finished()) {
            return;
        }
        rect.Move(velocity * (f32) delta);
        timer.Tick(delta);
    }
    void Draw(ZipLib::Renderer& renderer) { rect.Draw(renderer); }

public:
    ZipLib::Timer timer;

private:
    ZipLib::Shapes::ColoredRect rect;
    glm::vec2 velocity;

    inline static float TTL   = 5;
    inline static float Speed = 50;
};

class Tank {
public:
    Tank(glm::vec2 position, glm::vec4 color) : rect(position, 64, 64, color) {
        velocity = {0, 0};
        facing   = Direction::Left;
    }

    void Update(f64 delta) {
        if (ZipLib::Input.KeyDown(GLFW_KEY_A)) {
            velocity.x -= speed * delta;
            facing      = Direction::Left;
        } else if (ZipLib::Input.KeyDown(GLFW_KEY_D)) {
            velocity.x += speed * delta;
            facing      = Direction::Right;
        } else if (ZipLib::Input.KeyDown(GLFW_KEY_W)) {
            velocity.y += speed * delta;
            facing      = Direction::Up;
        } else if (ZipLib::Input.KeyDown(GLFW_KEY_S)) {
            velocity.y -= speed * delta;
            facing      = Direction::Down;
        }

        if (ZipLib::Input.KeyDown(GLFW_KEY_SPACE)) {
            bullets.push_back(Bullet(rect.pos, facing));
        }
        velocity /= decay_rate;

        rect.Move(velocity);

        for (u64 i = 0; i < bullets.size(); i++) {
            if (bullets[i].timer.Finished()) {
                bullets.erase(bullets.begin() + i);
            }
        }

        for (auto& bullet : bullets) {
            bullet.Update(delta);
        }
    }

    void Draw(ZipLib::Renderer& renderer) {
        rect.Draw(renderer);

        for (auto& bullet : bullets) {
            bullet.Draw(renderer);
        }
    }

private:
private:
    ZipLib::Shapes::ColoredRect rect;
    glm::vec2 velocity;
    Direction facing;
    std::vector<Bullet> bullets;
    const f32 speed      = 50;
    const f32 decay_rate = 1.2;
};

int main() {
    ZipLib::Window window(800, 800, "Hello world!", false);
    Tank tank({200, 200}, {1, 0, 1, 1});

    while (!window.ShouldClose()) {
        tank.Update(window.GetDeltaTime());
        window.renderer.Clear(24, 24, 24, 255);
        tank.Draw(window.renderer);
        window.Swap();
    }
    return 0;
}
