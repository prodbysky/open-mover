#pragma once
#include <string>
#include "types.h"

namespace StintaEngine::Utilities {
    using namespace Types;
    std::string read_entire_file(const char* fileName);
    f32 random_float(f32 min, f32 max);
}
