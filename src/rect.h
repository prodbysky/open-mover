#ifndef RECT_H
#define RECT_H

#include <string.h>
#include <glad/glad.h>
#include "types.h"

typedef struct {
    u32 VAO, VBO, EBO; 
    f32 x, y, h, w;
} rect_t;

rect_t rect_new(f32 x, f32 y, f32 w, f32 h, f32 r, f32 g, f32 b);
#endif
