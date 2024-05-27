#pragma once

#include "../Core/ebo.h"
#include "../Core/shader.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"
#include "../Utilities/types.h"
#include "rect.h"

#include <glm/glm.hpp>
#include <memory>

namespace ZipLib::Shapes {
    // Solid colored rectangle
    class ColoredRect : public Rect {
    private:
        std::shared_ptr<Core::Shader> shader;
        glm::vec4 color;

    public:
        ColoredRect(glm::vec2 pos, f32 w, f32 h,
                    std::shared_ptr<Core::Shader> shader,
                    glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        void Draw() const;
        void SetColor(glm::vec4 color);
    };
} // namespace ZipLib::Shapes
