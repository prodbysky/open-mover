#pragma once

#include "types.h"

#include <glad/glad.h>

class VAO {
private:
    u64 nextAttribOffset;
    u32 ID;
    u32 stride;
    u32 maxSize;
    u8 nextAttrib;
public:
    VAO() = default;
    VAO(u32 maxSize);
    void Bind();
    void Unbind();
    void AddAttribute(u32 size, GLenum type);
    void EnableAttribute(u32 attribute);
};
