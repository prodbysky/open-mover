#pragma once

#include "../Core/vao.h"

#include <glm/glm.hpp>

namespace ZipLib::Shapes {
    // Solid colored rectangle
    class Rect {
    public:
        Core::VBO vbo;
        Core::EBO ebo;
        Core::VAO vao;
        glm::mat4 model;
        glm::vec2 pos;
        f32 w, h;
        f32 rotation;

    public:
        Rect() = default;
        Rect(glm::vec2 pos, f32 w, f32 h);
        void Move(glm::vec2 move);
        void Rotate(f32 degrees);
        void SetRotation(f32 degrees);
        void FlipX();
        void FlipY();
        void SetPos(glm::vec2 new_pos);
        bool AABBCollision(const Rect& other) const;
        bool PointCollision(glm::vec2 point) const;
    };

} // namespace ZipLib::Shapes
