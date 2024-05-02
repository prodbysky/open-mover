#include "vbo.h"
#include <glad/glad.h>

VBO::VBO(f32 vertices[], u32 n) {
    glCreateBuffers(1, &ID);
    glNamedBufferData(ID, n * sizeof(f32), vertices, GL_STATIC_DRAW);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
