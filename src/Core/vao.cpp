#include <Core/vao.h>
#include <Utilities/assert.h>

namespace ZipLib::Core {
    VAO::VAO() {
        glCreateVertexArrays(1, &ID);
        nextAttribOffset = 0;
        nextAttrib       = 0;
        stride           = 0;
    }

    void VAO::Bind() const { glBindVertexArray(ID); }

    // TODO: Implement for all available types of attribute types
    template <> void VAO::AddAttribute<float>(u32 size) {
        Assert(size <= 4 && size != 0,
               "Passed in an invalid attribute size (0 < size <= 4");

        u32 elementSize = 4;

        EnableAttribute(nextAttrib);
        glVertexArrayAttribBinding(ID, nextAttrib, 0);
        glVertexArrayAttribFormat(ID, nextAttrib, size, GL_FLOAT, GL_FALSE,
                                  nextAttribOffset);

        nextAttribOffset  = elementSize * size;
        stride           += elementSize * size;
        nextAttrib++;
    }

    void VAO::EnableAttribute(u32 attribute) const {
        glEnableVertexArrayAttrib(ID, attribute);
    }

    void VAO::LinkVBOAndEBO(const VBO& vbo, const EBO& ebo) const {
        glVertexArrayVertexBuffer(ID, 0, vbo.ID, 0, stride);
        glVertexArrayElementBuffer(ID, ebo.ID);
    }
    void VAO::LinkVBO(const VBO& vbo) const {
        glVertexArrayVertexBuffer(ID, 0, vbo.ID, 0, stride);
    }
} // namespace ZipLib::Core
