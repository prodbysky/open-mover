#ifndef RECT_H
#define RECT_H

#include "ebo.h"
#include "types.h"
#include "vao.h"
#include "vbo.h"
#include "window.h"

typedef struct {
    vao_t vao;
    vbo_t vbo;
    ebo_t ebo;
    vec2s pos;
    vec3s color;
    f32 w, h;
    mat4 view;
} rect_t;

rect_t rect_new(vec2s pos, f32 w, f32 h, vec3s color);
void rect_draw(rect_t rect, window_t* window);
void rect_move(rect_t* rect, vec3s d);
void rect_color(rect_t* rect, vec3s c);
#endif
