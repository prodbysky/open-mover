#include "rect.h"
#include "glm/trigonometric.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <iostream>

namespace StintaEngine::Shapes {
    Rect::Rect(glm::vec2 pos, f32 w, f32 h) {
        this->pos = pos;
        this->w = w;
        this->h = h;
        model = glm::identity<glm::mat4>();
        vao = Core::VAO();
    }

    void Rect::Move(glm::vec3 move) {
        model = glm::translate(model, move);
        pos.x += move.x;
        pos.y += move.y;
    }

    void Rect::SetPos(glm::vec2 move) {
        model = glm::translate(model, glm::vec3(move.x - pos.x, move.y - pos.y, 0.0f));
        pos.x = move.x;
        pos.y = move.y;
    }

    void Rect::RotateX(f32 degrees) {
        model = glm::rotate(model, glm::radians(degrees), glm::vec3(1, 0, 0));
    }

    void Rect::RotateY(f32 degrees) {
        model = glm::rotate(model, glm::radians(degrees), glm::vec3(0, 1, 0));
    }
}
