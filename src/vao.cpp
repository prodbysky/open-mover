#include "vao.h"
#include <assert.h>
#include <stdbool.h>

VAO::VAO(u32 maxSize) {
    glGenVertexArrays(1, &ID);
    nextAttribOffset = 0;
    nextAttrib = 0;
    stride = 0;
    this->maxSize = maxSize;
}

void VAO::Bind() {
    glBindVertexArray(ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::AddAttribute(u32 size, GLenum type) {
    assert(size <= 4 && "Vertex attribute size more than 4");

    u32 elementSize;

    switch (type) {
        case GL_FLOAT: 
            elementSize = 4;
            break;
        default:
            assert(false && "Unimplemented attribute type");
    }

    glVertexAttribPointer(nextAttrib, size, type, GL_FALSE, maxSize * elementSize, (void*)nextAttribOffset);
    
    nextAttribOffset = elementSize * size;
    stride = elementSize * size;
    nextAttrib++;
}

void VAO::EnableAttribute(u32 attribute) {
    glEnableVertexAttribArray(attribute);
}
