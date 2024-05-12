#pragma once

#include <glm/glm.hpp>
#include "../Core/shader.h"

#include "../Core/ebo.h"
#include "../Utilities/types.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"
#include "rect.h"

namespace StintaEngine::Shapes {
    // Solid colored rectangle
    class ColoredRect {
    private:
        glm::vec3 color;
    public:
        Rect rect;
    public:
        ColoredRect(glm::vec2 pos, f32 w, f32 h, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));
        void Draw(Core::Shader& shader) const;
        void Move(glm::vec3 move);
        void SetPos(glm::vec2 move);
        void RotateX(f32 degrees);
        void RotateY(f32 degrees);
        void SetColor(glm::vec3 color);
    };
}
