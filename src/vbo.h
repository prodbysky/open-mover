#ifndef VBO_H
#define VBO_H

#include "types.h"

typedef u32 vbo_t;

vbo_t vbo_new(const f32* vertices, u32 n);
void vbo_bind(vbo_t vbo);
void vbo_unbind();

#endif // VBO_H
