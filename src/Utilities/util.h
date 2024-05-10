#pragma once
#include <string>
#include "types.h"

namespace StintaEngine::Utilities {
    std::string ReadEntireFile(const char* file_name);
    f32 RandomFloat(f32 min, f32 max);
}
