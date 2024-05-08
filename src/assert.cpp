#include "assert.h"

#include <iostream>

namespace StintaEngine {
    void Assert_(bool condition, const char* message, int line, const char* file) {
        if (condition) {
            return;
        }
        std::cerr << "Assertion failed, line: " << line << ", file: " << file << ": " << message << '\n';
        std::exit(0);
    }
}
