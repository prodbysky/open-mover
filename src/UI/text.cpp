#include "text.h"

namespace ZipLib::UI {
    Text::Text(const Font& font, std::string text, glm::vec2 pos,
               glm::vec3 color, f32 scale) :
        font(font), text(text), color(color), pos(pos), scale(scale) {

        vbo = Core::VBO(nullptr, 24, GL_DYNAMIC_DRAW);

        vao.AddAttribute<float>(4);
        vao.LinkVBO(vbo);
    }

    void Text::Move(glm::vec2 move) { pos += move; }

    void Text::SetPos(glm::vec2 move) { pos = move; }

    void Text::SetColor(glm::vec3 color) { this->color = color; }

    void Text::SetText(std::string text) { this->text = text; }

    void Text::SetScale(f32 scale) { this->scale = scale; }

    void Text::Draw(Renderer& renderer) {

        draw_call = {
            .type          = Core::ShaderType::SHADER_FONT,
            .vao           = vao,
            .vertex_count  = 6,
            .using_indices = false,
            .texture       = {},
            .PreDraw =
                [this]() {
                    glNamedBufferSubData(vbo.ID, 0, 24 * sizeof(f32),
                                         vertices.data());
                },
            .SetUniforms =
                [this, &renderer]() {
                    renderer.shader->SetUniform(color.r, color.g, color.b,
                                                "uColor");
                },
        };

        glm::vec2 saved_pos = pos;

        for (const char& c : text) {
            Character ch = font.chars.at(c);

            float xpos = pos.x + ch.bearing.x * scale;
            float ypos = pos.y - (ch.size.y - ch.bearing.y) * scale;

            float w = ch.size.x * scale;
            float h = ch.size.y * scale;

            vertices = {xpos, ypos + h, 0.0f,     0.0f,     xpos,     ypos,
                        0.0f, 1.0f,     xpos + w, ypos,     1.0f,     1.0f,
                        xpos, ypos + h, 0.0f,     0.0f,     xpos + w, ypos,
                        1.0f, 1.0f,     xpos + w, ypos + h, 1.0f,     0.0f};
            draw_call.texture = ch.texture;

            renderer.Draw(draw_call);

            pos.x += (ch.advance >> 6) * scale;
        }
        pos = saved_pos;
    }
} // namespace ZipLib::UI
