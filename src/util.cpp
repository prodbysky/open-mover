#include <string>
#include <fstream>
#include <sstream>

#include "util.h"

namespace StintaEngine::Utilities {
    std::string read_entire_file(const char* fileName) {
        std::ifstream t(fileName);
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }

    f32 random_float(f32 min, f32 max) { 
        return ((f32)rand() / RAND_MAX) * (max - min) + min; 
    };
}
