#pragma once

#include "types.h"

class EBO {
public:
    u32 ID;
public:
    EBO() = default;
    EBO(u32 indices[], u32 n);
    void Bind();
    void Unbind();
};
