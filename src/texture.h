#pragma once
#include "types.h"

typedef u32 texture_t; 
class Texture {
private:
    u32 ID;

public:
    // TODO: Fully featured texture function
    Texture() = default;
    Texture(const char* name);
    void Bind();
    void Unbind();
};
