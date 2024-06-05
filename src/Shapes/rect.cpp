#include "rect.h"

#include <glm/ext/matrix_transform.hpp>

namespace ZipLib::Shapes {
    Rect::Rect(glm::vec2 pos, f32 w, f32 h) {
        this->pos = pos;
        this->w   = w;
        this->h   = h;
        rotation  = 0;
        model     = glm::identity<glm::mat4>();
        vao       = Core::VAO();
    }

    void Rect::Move(glm::vec2 move) {
        model  = glm::translate(model, glm::vec3(move.x, move.y, 0));
        pos.x += move.x;
        pos.y += move.y;
    }

    // BUG: Majorly broken
    void Rect::Rotate(f32 degrees) {
        glm::vec3 center = glm::vec3(w / 2, h / 2, 0.0f);

        model = glm::translate(model, center);
        model =
            glm::rotate(model, glm::radians(degrees), glm::vec3(0.0, 0.0, 1.0));
        model    = glm::translate(model, -center);
        rotation = degrees;
    }

    void Rect::SetRotation(f32 degrees) {
        Rotate(-rotation);
        Rotate(degrees);
    }

    void Rect::FlipX() {
        glm::vec3 center = glm::vec3(w / 2, h / 2, 0.0);
        model            = glm::translate(model, center);
        model =
            glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0, 1.0, 0.0));
        model = glm::translate(model, -center);
    }

    void Rect::FlipY() {
        glm::vec3 center = glm::vec3(w / 2, h / 2, 0.0);
        model            = glm::translate(model, center);
        model =
            glm::rotate(model, glm::radians(180.0f), glm::vec3(1.0, 0.0, 0.0));
        model = glm::translate(model, -center);
    }

    void Rect::SetPos(glm::vec2 new_pos) {
        model = glm::translate(
            model, glm::vec3(new_pos.x - pos.x, new_pos.y - pos.y, 0.0f));
        pos.x = new_pos.x;
        pos.y = new_pos.y;
    }

    bool Rect::AABBCollision(const Rect& other) const {
        return this->pos.x<other.pos.x + other.w&& this->pos.x + this->w> other
                   .pos.x &&
               this->pos.y<other.pos.y + other.h&& this->pos.y + this->h> other
                   .pos.y;
    }

    bool Rect::PointCollision(glm::vec2 point) const {
        return point.x >= pos.x && point.x <= pos.x + w && point.y <= pos.y &&
               point.y >= pos.y - h;
    }
} // namespace ZipLib::Shapes
