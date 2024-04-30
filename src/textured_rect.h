#ifndef TEXTURED_RECT_H
#define TEXTURED_RECT_H

#include <cglm/struct.h>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"

typedef struct {
    vao_t vao;
    vbo_t vbo;
    ebo_t ebo;
    vec2s pos;
    f32 w, h;
    mat4 view;
    u32 texture;
} textured_rect_t;

textured_rect_t textured_rect_new(vec2s pos, f32 w, f32 h, const char* textureName);
void textured_rect_draw(textured_rect_t rect, shader_t* shader);

#endif // TEXTURED_RECT_H