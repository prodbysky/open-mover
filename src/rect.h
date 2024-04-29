#ifndef RECT_H
#define RECT_H

#include <string.h>

#include <glad/glad.h>
#include <cglm/struct.h>

#include "types.h"
#include "shader.h"

typedef struct {
    u32 VAO, VBO, EBO; 
    vec2s pos;
    vec3s color;
    f32 w, h;
} rect_t;

rect_t rect_new(vec2s pos, f32 w, f32 h, vec3s color);
void rect_draw(rect_t rect, shader_t shader);
#endif
