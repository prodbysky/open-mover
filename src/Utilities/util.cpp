#include <string>
#include <fstream>
#include <sstream>

#include "util.h"

namespace StintaEngine::Utilities {
    std::string ReadEntireFile(const char* file_name) {
        std::ifstream t(file_name);
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }

    f32 RandomFloat(f32 min, f32 max) { 
        return ((f32)rand() / RAND_MAX) * (max - min) + min; 
    };
}