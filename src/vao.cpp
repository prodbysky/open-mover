#include "vao.h"
#include "assert.h"
#include "glad/glad.h"
#include "vbo.h"
#include <cassert>
#include <stdbool.h>

namespace StintaEngine::Core {
    VAO::VAO() {
        glCreateVertexArrays(1, &ID);
        nextAttribOffset = 0;
        nextAttrib = 0;
        stride = 0;
    }

    void VAO::Bind() {
        glBindVertexArray(ID);
    }

    void VAO::AddAttribute(u32 size, GLenum type) {
        Assert(size <= 4 && size != 0, "Passed in an invalid attribute size (0 < size <= 4");

        u32 elementSize;

        switch (type) {
            case GL_FLOAT: 
                elementSize = 4;
                break;
            default:
                Assert(false, "Unimplemented attribute type");
        }

        
        EnableAttribute(nextAttrib);
        glVertexArrayAttribBinding(ID, nextAttrib, 0);
        glVertexArrayAttribFormat(ID, nextAttrib, size, type, GL_FALSE, nextAttribOffset);
        
        nextAttribOffset = elementSize * size;
        stride += elementSize * size;
        nextAttrib++;
    }

    void VAO::EnableAttribute(u32 attribute) {
        glEnableVertexArrayAttrib(ID, attribute);
    }

    void VAO::LinkVBOAndEBO(const VBO& vbo, const EBO& ebo) {
        glVertexArrayVertexBuffer(ID, 0, vbo.ID, 0, stride);
        glVertexArrayElementBuffer(ID, ebo.ID);
    }
    void VAO::LinkVBO(const VBO& vbo) {
        glVertexArrayVertexBuffer(ID, 0, vbo.ID, 0, stride);
    }
}
