#pragma once

#include <glm/glm.hpp>
#include "../Core/shader.h"

#include "../Core/ebo.h"
#include "../Utilities/types.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"

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
        void Move(glm::vec3 move);
        void SetPos(glm::vec2 move);
        void RotateX(f32 degrees);
        void RotateY(f32 degrees);
        bool AABBCollision(const Rect& other);
        bool PointCollision(glm::vec2 point);
    };

}
