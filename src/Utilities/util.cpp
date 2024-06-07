#include "util.h"

#include <cmath>
#include <fstream>
#include <random>
#include <sstream>
#include <string>

namespace ZipLib::Utilities {
    std::string ReadEntireFile(const char* file_name) {
        std::ifstream t(file_name);
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }

    void RNG::Init() {
        std::random_device dev;
        RNG::rng = std::mt19937(dev());
    }
} // namespace ZipLib::Utilities
