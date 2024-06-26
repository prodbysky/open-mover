#pragma once

#include "rect.h"

#include <Window/renderer.h>

namespace ZipLib::Shapes {
    // Solid colored rectangle
    class ColoredRect : public Rect {
    private:
        DrawCall draw_call;
        glm::vec4 color;

    public:
        ColoredRect(glm::vec2 pos, f32 w, f32 h,
                    glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        void Draw(Renderer& renderer);
        void SetColor(glm::vec4 color);
    };
} // namespace ZipLib::Shapes
