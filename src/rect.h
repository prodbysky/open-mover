#ifndef RECT_H
#define RECT_H

#include <string.h>
#include <glad/glad.h>
#include <cglm/struct.h>
#include "types.h"

typedef struct {
    u32 VAO, VBO, EBO; 
    vec2s pos;
    f32 w, h;
} rect_t;

rect_t rect_new(vec2s pos, f32 w, f32 h, vec3s color);
#endif
