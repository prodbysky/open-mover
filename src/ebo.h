#pragma once

#include "types.h"

namespace StintaEngine::Core {
    // Manages index buffers
    class EBO {
    public:
        u32 ID;
    public:
        EBO() = default;
        EBO(u32 indices[], u32 n);
    };
}
