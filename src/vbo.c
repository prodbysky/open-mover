#include "vbo.h"
#include <glad/glad.h>

vbo_t vbo_new(const f32* vertices, u32 n) {
    vbo_t vbo;

    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, n * sizeof(f32), vertices, GL_STATIC_DRAW);
    return vbo; 
}

void vbo_bind(vbo_t vbo) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void vbo_unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

