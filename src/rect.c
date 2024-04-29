#include "rect.h"
#include "cglm/mat4.h"
#include "shader.h"


rect_t rect_new(vec2s pos, f32 w, f32 h, vec3s color) {
    rect_t rect; 

    rect.pos = pos;
    rect.w = w;
    rect.h = h;
    rect.color = color;
    glm_mat4_identity(rect.view);

    const u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
    const f32 temp_vertices[] = {
        pos.x,     pos.y,     1.0f, 
        pos.x + w, pos.y,     1.0f,  
        pos.x + w, pos.y - h, 1.0f,  
        pos.x,     pos.y - h, 1.0f,  
    };

    glGenBuffers(1, &rect.EBO);
    glGenVertexArrays(1, &rect.VAO);
    glGenBuffers(1, &rect.VBO);
    
    glBindVertexArray(rect.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, rect.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_vertices), temp_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rect.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(temp_indices), temp_indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return rect;
}

void rect_move(rect_t* rect, vec3s d) {
    glm_translate(rect->view, d.raw);
    rect->pos.x += d.x;
    rect->pos.y += d.y;
}

void rect_draw(rect_t rect, shader_t shader) {
    shader_set_vec3f(shader, rect.color, "uColor");
    shader_set_mat4f(shader, rect.view, "uView");
    glBindVertexArray(rect.VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void rect_color(rect_t* rect, vec3s c) {
    rect->color = c;
}
