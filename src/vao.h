#pragma once

#include "ebo.h"
#include "types.h"
#include "vbo.h"

#include <glad/glad.h>

namespace StintaEngine::Core {
    using namespace Types;
    class VAO {
    private:
        u64 nextAttribOffset;
        u32 stride;
        u32 ID;
        u8 nextAttrib;
    private:
        void EnableAttribute(u32 attribute) const;
    public:
        VAO();
        // Binds the VAO for drawing or other purposes
        void Bind() const;
        // Adds a attribute of `size`, and of `type`
        void AddAttribute(u32 size, GLenum type);
        // Use when drawing with glDrawElements()
        void LinkVBOAndEBO(const VBO& vbo, const EBO& ebo) const;
        // Use when drawing with glDrawArrays()
        void LinkVBO(const VBO& vbo) const;
    };
}
