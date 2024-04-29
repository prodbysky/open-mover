#include "rect.h"

rect_t rect_new(f32 x, f32 y, f32 w, f32 h, f32 r, f32 g, f32 b) {
    rect_t rect; 

    const u32 temp[] = {0, 1, 2, 0, 2, 3};
    memcpy(rect.indices, temp, sizeof(temp));

    const f32 temp_verts[] = {
        x,     y, 1.0f, r, g, b, 
        x + w, y, 1.0f, r, g, b, 
        x + w, y - h, 1.0f, r, g, b, 
        x,     y - h, 1.0f, r, g, b, 
    };
    memcpy(rect.vertices, temp_verts, sizeof(temp_verts));

    glGenBuffers(1, &rect.EBO);
    glGenVertexArrays(1, &rect.VAO);
    glGenBuffers(1, &rect.VBO);
    
    glBindVertexArray(rect.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, rect.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rect.vertices), rect.vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rect.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rect.indices), rect.indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(f32), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(f32), (void*)(3 * sizeof(f32)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return rect;
}

