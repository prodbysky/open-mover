#pragma once

#include "ebo.h"
#include "types.h"
#include "vao.h"
#include "vbo.h"
#include "window.h"

class Rect {
private:
    VAO vao;
    VBO vbo;
    EBO ebo;
    glm::vec3 color;
    glm::mat4 model;
public:
    glm::vec2 pos;
    f32 w, h;
public:
    Rect(glm::vec2 pos, f32 w, f32 h, glm::vec3 color);
    void Draw(Shader& shader);
    void Move(glm::vec3 move);
    void SetPos(glm::vec2 move);
    void SetColor(glm::vec3 color);
};
