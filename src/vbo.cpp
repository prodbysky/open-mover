#include "vbo.h"
#include <cassert>
#include <glad/glad.h>

VBO::VBO(f32 vertices[], u32 n, GLenum type) {
    assert(n != 0);
    glCreateBuffers(1, &ID);
    glNamedBufferData(ID, n * sizeof(f32), vertices, type);
}
