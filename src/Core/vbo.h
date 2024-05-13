#pragma once

#include "../Utilities/types.h"

#include <glad/glad.h>

namespace ZipLib::Core {
    class VBO {
      public:
        u32 ID;

      public:
        VBO() = default;
        VBO(f32 vertices[], u32 n, GLenum type = GL_STATIC_DRAW);
    };
} // namespace ZipLib::Core
