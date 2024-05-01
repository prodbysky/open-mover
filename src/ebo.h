#pragma once

#include "types.h"

class EBO {
private:
    u32 ID;
public:
    EBO() = default;
    EBO(u32 indices[], u32 n);
    void Bind();
    void Unbind();
};
