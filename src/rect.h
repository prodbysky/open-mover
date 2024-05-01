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
    vec3s color;
    mat4 model;
public:
    vec2s pos;
    f32 w, h;
public:
    Rect(vec2s pos, f32 w, f32 h, vec3s color);
    void Draw(Shader& shader);
    void Move(vec3s move);
    void SetPos(vec2s move);
    void SetColor(vec3s color);
};
