
#include "ebo.h"
#include <glad/glad.h>

ebo_t ebo_new(const u32* vertices, u32 n) {
    ebo_t ebo;

    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, n * sizeof(u32), vertices, GL_STATIC_DRAW);
    return ebo; 
}

void ebo_bind(ebo_t ebo) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}

void ebo_unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

