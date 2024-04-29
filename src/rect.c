#include "rect.h"


rect_t rect_new(vec2s pos, f32 w, f32 h, vec3s color) {
    rect_t rect; 

    rect.pos.x = pos.x;
    rect.pos.y = pos.y;
    rect.w = w;
    rect.h = h;

    const u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
    const f32 temp_vertices[] = {
        pos.x,     pos.y,     1.0f, color.r, color.g, color.b, 
        pos.x + w, pos.y,     1.0f, color.r, color.g, color.b, 
        pos.x + w, pos.y - h, 1.0f, color.r, color.g, color.b, 
        pos.x,     pos.y - h, 1.0f, color.r, color.g, color.b, 
    };

    glGenBuffers(1, &rect.EBO);
    glGenVertexArrays(1, &rect.VAO);
    glGenBuffers(1, &rect.VBO);
    
    glBindVertexArray(rect.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, rect.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_vertices), temp_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rect.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(temp_indices), temp_indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(f32), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(f32), (void*)(3 * sizeof(f32)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return rect;
}

void rect_draw(rect_t rect) {
    glBindVertexArray(rect.VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

