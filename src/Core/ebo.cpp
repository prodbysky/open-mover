#include "ebo.h"
#include "assert.h"
#include <glad/glad.h>

namespace StintaEngine::Core {
    EBO::EBO(u32 indices[], u32 n) {
        Assert(n != 0, "Passed in n = 0");
        glCreateBuffers(1, &ID);
        glNamedBufferData(ID, n * sizeof(u32), indices, GL_STATIC_DRAW);
    }
}
