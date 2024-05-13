#pragma once

#include "../Utilities/types.h"
#include "../Utilities/assert.h"

namespace ZipLib::Core {
    // Manages index buffers
    class EBO {
    public:
        u32 ID;
    public:
        EBO() = default;
        EBO(u32 indices[], u32 n);
    };
}
