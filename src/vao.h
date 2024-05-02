#pragma once

#include "ebo.h"
#include "types.h"
#include "vbo.h"

#include <glad/glad.h>

class VAO {
private:
    u64 nextAttribOffset;
    u32 ID;
    u32 stride;
    u32 maxSize;
    u8 nextAttrib;
public:
    VAO();
    void Bind();
    void AddAttribute(u32 size, GLenum type);
    void Finalize(const VBO& vbo, const EBO& ebo);
    void EnableAttribute(u32 attribute);
};
