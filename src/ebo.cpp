#include "ebo.h"
#include <glad/glad.h>

EBO::EBO(u32 indices[], u32 n) {
    glCreateBuffers(1, &ID);
    glNamedBufferData(ID, n * sizeof(u32), indices, GL_STATIC_DRAW);
}
