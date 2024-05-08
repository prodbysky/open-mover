#pragma once

#include "ebo.h"
#include "types.h"
#include "vbo.h"

#include <glad/glad.h>

class VAO {
private:
    u64 nextAttribOffset;
    u32 stride;
    u8 nextAttrib;
    u32 ID;
private:
    void EnableAttribute(u32 attribute);
public:
    VAO();
    void Bind();
    void AddAttribute(u32 size, GLenum type);
    // Use when drawing with glDrawElements()
    void LinkVBOAndEBO(const VBO& vbo, const EBO& ebo);
    // Use when drawing with glDrawArrays()
    void LinkVBO(const VBO& vbo);
};
