#pragma once

#define Assert(condition, message) Assert_(condition, message, __LINE__, __FILE__)

namespace StintaEngine {
    void Assert_(bool condition, const char* message, int line, const char* file);
}
