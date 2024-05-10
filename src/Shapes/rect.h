#pragma once

#include <glm/glm.hpp>
#include "../Core/shader.h"

#include "../Core/ebo.h"
#include "../Utilities/types.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"

namespace StintaEngine {
    // Solid colored rectangle
    class Rect {
    private:
        Core::VAO vao;
        Core::VBO vbo;
        Core::EBO ebo;
        glm::vec3 color;
        glm::mat4 model;
    public:
        glm::vec2 pos;
        f32 w, h;
    public:
        Rect(glm::vec2 pos, f32 w, f32 h, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));
        void Draw(Core::Shader& shader) const;
        void Move(glm::vec3 move);
        void SetPos(glm::vec2 move);
        void SetColor(glm::vec3 color);
    };
}
