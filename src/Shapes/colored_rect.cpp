#include "colored_rect.h"

namespace ZipLib::Shapes {
    ColoredRect::ColoredRect(glm::vec2 pos, f32 w, f32 h, glm::vec4 color) :
        Rect(pos, w, h), color(color) {
        u32 temp_indices[]  = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x,     pos.y,     1.0f, pos.x + w, pos.y,     1.0f,
            pos.x + w, pos.y - h, 1.0f, pos.x,     pos.y - h, 1.0f,
        };

        vbo = Core::VBO(temp_vertices, 12);
        ebo = Core::EBO(temp_indices, 6);

        vao.AddAttribute<float>(3);
        vao.LinkVBOAndEBO(vbo, ebo);
    }

    void ColoredRect::Draw(Renderer& renderer) {
        draw_call = {
            .type          = Core::ShaderType::SHADER_DEFAULT,
            .vao           = vao,
            .vertex_count  = 6,
            .using_indices = true,
            .texture       = {},
            .PreDraw       = []() {},
            .SetUniforms =
                [this, &renderer]() {
                    renderer.shader->SetUniform(color, "uColor");
                    renderer.shader->SetUniform(model, "uModel");
                },
        };

        renderer.Draw(draw_call);
    }

    void ColoredRect::SetColor(glm::vec4 color) { this->color = color; }
} // namespace ZipLib::Shapes
