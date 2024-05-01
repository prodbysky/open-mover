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
    vec2s pos;
    vec3s color;
    f32 w, h;
    mat4 model;
public:
    Rect(vec2s pos, f32 w, f32 h, vec3s color);
    void Draw(std::unique_ptr<Shader>& shader);
    void Move(vec3s move);
    void SetPos(vec2s move);
    void SetColor(vec3s color);
};
