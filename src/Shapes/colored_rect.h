#pragma once

#include "../Core/ebo.h"
#include "../Core/shader.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"
#include "../Utilities/types.h"
#include "rect.h"

#include <glm/glm.hpp>

namespace ZipLib::Shapes {
    // Solid colored rectangle
    class ColoredRect {
    private:
        glm::vec4 color;

    public:
        Rect rect;

    public:
        ColoredRect(glm::vec2 pos, f32 w, f32 h,
                    glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        void Draw(Core::Shader& shader) const;
        void Move(glm::vec3 move);
        void SetPos(glm::vec2 move);
        void SetColor(glm::vec4 color);
    };
} // namespace ZipLib::Shapes
