#pragma once

#include "types.h"

typedef u32 vbo_t;

class VBO {
private:
    u32 ID;

public:
    VBO() = default;
    VBO(f32 vertices[], u32 n);

    void Bind();
    void Unbind();
};

