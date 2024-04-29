#ifndef RECT_H
#define RECT_H

#include <string.h>

#include <glad/glad.h>
#include <cglm/struct.h>

#include "types.h"
#include "shader.h"
#include "vao.h"

typedef struct {
    u32 VBO, EBO; 
    vao_t vao;
    vec2s pos;
    vec3s color;
    f32 w, h;
    mat4 view;
} rect_t;

rect_t rect_new(vec2s pos, f32 w, f32 h, vec3s color);
void rect_draw(rect_t rect, shader_t shader);
void rect_move(rect_t* rect, vec3s d);
void rect_color(rect_t* rect, vec3s c);
#endif
