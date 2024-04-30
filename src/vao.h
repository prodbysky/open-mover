#ifndef VAO_H
#define VAO_H

#include "types.h"

#include <glad/glad.h>

typedef struct {
    u64 nextAttribOffset;
    u32 ID;
    u32 stride;
    u32 maxSize;
    u8 nextAttrib;
} vao_t;

vao_t vao_new(u32 maxSize);
void vao_bind(vao_t vao);
void vao_unbind();

void vao_add_attribute(vao_t* vao, u32 size, GLenum type);
void vao_enable_attribute(u32 attribute);

#endif // VAO_H
