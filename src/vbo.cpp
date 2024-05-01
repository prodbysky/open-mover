#include "vbo.h"
#include <glad/glad.h>

VBO::VBO(f32 vertices[], u32 n) {
    glGenBuffers(1, &ID);

    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, n * sizeof(f32), vertices, GL_STATIC_DRAW);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
