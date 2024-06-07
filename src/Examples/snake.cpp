#include "glm/ext/vector_float2.hpp"

#include <Core/ZipLib.h>
#include <Shapes/colored_rect.h>
#include <Window/renderer.h>
#include <Window/timer.h>
#include <Window/window.h>
#include <cstdlib>
#include <vector>

constexpr i32 WindowWidth  = 800;
constexpr i32 WindowHeight = 800;
constexpr f32 TileSize     = 80;
constexpr i32 TileCount    = WindowWidth / TileSize;

class Tile {
public:
    Tile() : rect({-1, -1}, 1, 1) {}
    Tile(glm::vec2 pos, glm::vec4 color) : rect({-1, -1}, 1, 1) {
        pos.y++;
        pos  *= TileSize;
        rect  = ZipLib::Shapes::ColoredRect(pos, TileSize, TileSize, color);
    }

    void Draw(ZipLib::Renderer& renderer) { rect.Draw(renderer); }
    void Move(glm::vec2 next) {
        next *= TileSize;
        rect.Move(next);
    }
    void SetPos(glm::vec2 next) {
        next *= TileSize;
        rect.SetPos(next);
    }

    bool Collision(const Tile& other) { return rect.pos == other.rect.pos; }

public:
    ZipLib::Shapes::ColoredRect rect;
};

class Fruit : public Tile {
public:
    Fruit() : Tile({5, 5}, {1, 0, 0, 1}) {}
    void Move() {
        i32 x = ZipLib::Random.Get(0, TileCount - 1);
        i32 y = ZipLib::Random.Get(0, TileCount - 1);
        if (y == 0)
            y++;
        SetPos({x, y});
    }
};

class Player : public Tile {
public:
    Player() : Tile({0, 0}, {0, 0, 1, 1}) {}
    void Update() {
        if (ZipLib::Input.KeyDown(GLFW_KEY_A) && velocity.x != 1) {
            velocity.x = -1;
            velocity.y = 0;
        }

        if (ZipLib::Input.KeyDown(GLFW_KEY_D) && velocity.x != -1) {
            velocity.x = 1;
            velocity.y = 0;
        }

        if (ZipLib::Input.KeyDown(GLFW_KEY_W) && velocity.y != -1) {
            velocity.y = 1;
            velocity.x = 0;
        }

        if (ZipLib::Input.KeyDown(GLFW_KEY_S) && velocity.y != 1) {
            velocity.y = -1;
            velocity.x = 0;
        }
    }

    void Move() { rect.Move(velocity * TileSize); }

private:
    glm::vec2 velocity = {0, 0};
};

class Snake {
public:
    Snake() = default;
    void Draw(ZipLib::Renderer& renderer) {
        for (auto& tile : body) {
            tile.Draw(renderer);
        }
        head.Draw(renderer);
    }

    void Collision() {
        for (u64 i = 1; i < body.size(); i++) {
            auto& tail_part = body[i];
            if (tail_part.Collision(head)) {
                exit(0);
            }
        }
    }

    void Update(Fruit& fruit) {
        if (body.size() != 0) {
            for (i64 i = body.size() - 1; i >= 0; i--) {
                Tile& part = body[i];

                if (i == 0) {
                    part.SetPos(head.rect.pos / TileSize);
                } else {
                    Tile& previous_part = body[i - 1];
                    part.SetPos(previous_part.rect.pos / TileSize);
                }
            }
        }

        Collision();

        head.Move();

        if (head.Collision(fruit)) {
            glm::vec2 next_pos = fruit.rect.pos / TileSize;
            next_pos.y--;
            body.push_back(Tile(next_pos, {0.5, 0, 0, 1}));
            fruit.Move();
        }
    }

public:
    Player head;

private:
    std::vector<Tile> body;
};

i32 main() {
    ZipLib::Window window({.width  = WindowWidth,
                           .height = WindowHeight,
                           .title  = "Hello!",
                           .v_sync = true});
    ZipLib::Timer timer(1);

    Snake snake;
    Fruit fruit;

    timer.Start();
    while (!window.ShouldClose()) {
        snake.head.Update();

        timer.Tick(window.GetDeltaTime());
        if (timer.Finished()) {
            snake.Update(fruit);
            timer.Extend(0.1);
            timer.Start();
        }
        window.renderer.Clear(0, 0, 0, 0);
        snake.Draw(window.renderer);
        fruit.Draw(window.renderer);
        window.Swap();
    }
}
