#pragma once

#include <cglm/struct.h>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "window.h"

typedef struct {
    vao_t vao;
    vbo_t vbo;
    ebo_t ebo;
    vec2s pos;
    f32 w, h;
    mat4 model;
    u32 texture;
} textured_rect_t;

textured_rect_t textured_rect_new(vec2s pos, f32 w, f32 h, const char* textureName);
void textured_rect_draw(textured_rect_t rect, window_t* window);
void textured_rect_move(textured_rect_t* rect, vec2s d);
void textured_rect_set_pos(textured_rect_t* rect, vec2s d);
