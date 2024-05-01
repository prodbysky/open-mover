#pragma once

#include <cglm/struct.h>
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
    mat4 model;
    Texture texture;
public:
    vec2s pos;
    f32 w, h;
public:
    // TODO: again options for the textures
    TexturedRect() = default;
    TexturedRect(vec2s pos, f32 w, f32 h, const char* textureName);
    void Draw(Shader& shader);
    void Move(vec2s move);
    void SetPos(vec2s move);
};
