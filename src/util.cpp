#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>

#include "util.h"

std::string read_entire_file(const char* fileName) {
    std::ifstream t(fileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}
