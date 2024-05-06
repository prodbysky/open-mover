#include "vbo.h"
#include <glad/glad.h>

VBO::VBO(f32 vertices[], u32 n, GLenum type) {
    glCreateBuffers(1, &ID);
    glNamedBufferData(ID, n * sizeof(f32), vertices, type);
}
