#include "vao.h"
#include <assert.h>
#include <stdbool.h>

vao_t vao_new(u32 maxSize) {
    vao_t vao;
    glGenVertexArrays(1, &vao.ID);
    vao.nextAttribOffset = 0;
    vao.nextAttrib = 0;
    vao.stride = 0;
    vao.maxSize = maxSize;
    return vao;
}

void vao_bind(vao_t vao) {
    glBindVertexArray(vao.ID);
}

void vao_unbind() {
    glBindVertexArray(0);
}

void vao_add_attribute(vao_t* vao, u32 size, GLenum type) {
    assert(size <= 4 && "Vertex attribute size more than 4");

    u32 elementSize;

    switch (type) {
        case GL_FLOAT: 
            elementSize = 4;
            break;
        default:
            assert(false && "Unimplemented attribute type");
    }

    glVertexAttribPointer(vao->nextAttrib, size, type, GL_FALSE, vao->maxSize * elementSize, (void*)vao->nextAttribOffset);
    
    vao->nextAttribOffset = elementSize * size;
    vao->stride = elementSize * size;
    vao->nextAttrib++;
}
void vao_enable_attribute(u32 attribute) {
    glEnableVertexAttribArray(attribute);
}
