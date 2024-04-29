#include "rect.h"
#include "cglm/mat4.h"
#include "ebo.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"


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

    rect.vao = vao_new(3);
    vao_bind(rect.vao);
    rect.vbo = vbo_new(temp_vertices, 12);
    rect.ebo = ebo_new(temp_indices, 6);

    vao_add_attribute(&rect.vao, 3, GL_FLOAT);
    vao_enable_attribute(0);

    vao_unbind();
    vbo_unbind();
    ebo_unbind();

    return rect;
}

void rect_move(rect_t* rect, vec3s d) {
    glm_translate(rect->view, d.raw);
    rect->pos.x += d.x;
    rect->pos.y += d.y;
}

void rect_draw(rect_t rect, shader_t shader) {
    shader_use(shader);
    shader_set_vec3f(shader, rect.color, "uColor");
    shader_set_mat4f(shader, rect.view, "uView");
    vao_bind(rect.vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void rect_color(rect_t* rect, vec3s c) {
    rect->color = c;
}
