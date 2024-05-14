#pragma once

#include "../Core/ebo.h"
#include "../Core/shader.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"
#include "../Utilities/types.h"

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

    public:
        Rect() = default;
        Rect(glm::vec2 pos, f32 w, f32 h);
        void Move(glm::vec2 move);
        void SetPos(glm::vec2 new_pos);
        bool AABBCollision(const Rect& other) const;
        bool PointCollision(glm::vec2 point) const;
    };

} // namespace ZipLib::Shapes
