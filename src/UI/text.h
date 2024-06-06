#pragma once

#include <Resource/resources.h>
#include <Window/renderer.h>

namespace ZipLib::UI {
    class Text {

    public:
        Text(const Font& font, std::string text, glm::vec2 pos, glm::vec3 color,
             f32 scale);
        void Move(glm::vec2 move);
        void SetPos(glm::vec2 move);
        void SetColor(glm::vec3 color);
        void SetText(std::string text);
        void SetScale(f32 scale);
        void Draw(Renderer& renderer);

    private:
        std::array<f32, 24> vertices;
        DrawCall draw_call;
        const Font& font;
        std::string text;
        Core::VAO vao;
        Core::VBO vbo;
        glm::vec3 color;
        glm::vec2 pos;
        f32 scale;
    };
}; // namespace ZipLib::UI
