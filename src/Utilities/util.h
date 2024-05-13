#pragma once
#include "types.h"

#include <string>

namespace ZipLib::Utilities {
    std::string ReadEntireFile(const char *file_name);
    f32 RandomFloat(f32 min, f32 max);
} // namespace ZipLib::Utilities
