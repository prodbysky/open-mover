#pragma once

#include <glad/glad.h>

#include "types.h"

namespace StintaEngine::Core {
    class VBO {
    public:
        u32 ID;
    public:
        VBO() = default;
        VBO(f32 vertices[], u32 n, GLenum type = GL_STATIC_DRAW);
    };
}

