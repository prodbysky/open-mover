#pragma once

#include "types.h"

#define Assert(condition, message) Assert_(condition, message, __LINE__, __FILE__)

namespace StintaEngine {
    // Assert function that calls `std::exit(0)` when `condition` is false
    void Assert_(bool condition, const char* message, i32 line, const char* file);
}
