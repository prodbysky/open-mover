#pragma once

#include <memory>

#include "texture.h"
#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "window.h"

class TexturedRect {
private:
    VAO vao;
    VBO vbo;
    EBO ebo;
    glm::mat4 model;
    Texture texture;
public:
    glm::vec2 pos;
    f32 w, h;
public:
    // TODO: again options for the textures
    TexturedRect() = default;
    TexturedRect(glm::vec2 pos, f32 w, f32 h, const char* textureName);
    void Draw(Shader& shader);
    void Move(glm::vec2 move);
    void SetPos(glm::vec2 move);
};
