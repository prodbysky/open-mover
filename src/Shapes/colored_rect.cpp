#include "colored_rect.h"

#include "../Core/ebo.h"
#include "../Core/shader.h"
#include "../Core/vao.h"

#include <glm/ext/matrix_transform.hpp>
#include <memory>

namespace ZipLib::Shapes {
    ColoredRect::ColoredRect(glm::vec2 pos, f32 w, f32 h,
                             std::shared_ptr<Core::Shader> shader,
                             glm::vec4 color) :
        Rect(pos, w, h), shader(shader), color(color) {
        u32 temp_indices[]  = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x,     pos.y,     1.0f, pos.x + w, pos.y,     1.0f,
            pos.x + w, pos.y - h, 1.0f, pos.x,     pos.y - h, 1.0f,
        };

        vbo = Core::VBO(temp_vertices, 12);
        ebo = Core::EBO(temp_indices, 6);

        vao.AddAttribute(3, GL_FLOAT);
        vao.LinkVBOAndEBO(vbo, ebo);
    }

    void ColoredRect::Draw() const {
        shader->SetShader(Core::ShaderType::SHADER_DEFAULT);
        shader->SetUniform(color, "uColor");
        shader->SetUniform(model, "uModel");
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void ColoredRect::SetColor(glm::vec4 color) { this->color = color; }
} // namespace ZipLib::Shapes
