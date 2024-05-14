#include "colored_rect.h"

#include "../Core/ebo.h"
#include "../Core/shader.h"
#include "../Core/vao.h"

#include <glm/ext/matrix_transform.hpp>

namespace ZipLib::Shapes {
    ColoredRect::ColoredRect(glm::vec2 pos, f32 w, f32 h, glm::vec4 color) :
        rect(pos, w, h) {
        this->color = color;

        u32 temp_indices[]  = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x,     pos.y,     1.0f, pos.x + w, pos.y,     1.0f,
            pos.x + w, pos.y - h, 1.0f, pos.x,     pos.y - h, 1.0f,
        };

        rect.vbo = Core::VBO(temp_vertices, 12);
        rect.ebo = Core::EBO(temp_indices, 6);

        rect.vao.AddAttribute(3, GL_FLOAT);
        rect.vao.LinkVBOAndEBO(rect.vbo, rect.ebo);
    }

    void ColoredRect::Move(glm::vec2 move) { rect.Move(move); }

    void ColoredRect::Draw(Core::Shader& shader) const {
        shader.SetShader(Core::ShaderType::SHADER_DEFAULT);
        shader.SetUniform(color, "uColor");
        shader.SetUniform(rect.model, "uModel");
        rect.vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void ColoredRect::SetColor(glm::vec4 color) { this->color = color; }

    void ColoredRect::SetPos(glm::vec2 move) { rect.SetPos(move); }
} // namespace ZipLib::Shapes
