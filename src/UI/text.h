#pragma once

#include <glm/glm.hpp>
#include <string>
#include <memory>
#include "../Resource/resources.h"
#include "../Core/shader.h"
#include "../Core/vao.h"
#include "../Core/vbo.h"

namespace ZipLib::UI {
    class Text {
    private:
        const Font& font;
        std::string text;
        std::unique_ptr<Core::VAO> vao;
        std::unique_ptr<Core::VBO> vbo;
        glm::vec3 color;
        glm::vec2 pos;
        f32 scale;
    public:
        Text(const Font& font, std::string text, glm::vec2 pos, glm::vec3 color, f32 scale);
        void Move(glm::vec2 move); 
        void SetPos(glm::vec2 move);
        void SetColor(glm::vec3 color);
        void SetText(std::string text);
        void SetScale(f32 scale);
        void Draw(Core::Shader& shader);
    };
};
