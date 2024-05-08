#include "vbo.h"
#include "assert.h"
#include <cassert>
#include <glad/glad.h>


namespace StintaEngine::Core {
    VBO::VBO(f32 vertices[], u32 n, GLenum type) {
        Assert(n != 0, "Passed in 0 as the size of the vertices array");
        glCreateBuffers(1, &ID);
        glNamedBufferData(ID, n * sizeof(f32), vertices, type);
    }
}
