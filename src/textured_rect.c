#include "textured_rect.h"
#include "cglm/struct/vec3.h"
#include "texture.h"

textured_rect_t textured_rect_new(vec2s pos, f32 w, f32 h, const char* textureName) {
    textured_rect_t tRect;
    tRect.pos = pos;
    tRect.w = w;
    tRect.h = h;
    glm_mat4_identity(tRect.model);

    const u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
    const f32 temp_vertices[] = {
        pos.x,     pos.y,     1.0f, 0.0f, 1.0f,
        pos.x + w, pos.y,     1.0f, 1.0f, 1.0f,
        pos.x + w, pos.y - h, 1.0f, 1.0f, 0.0f,
        pos.x,     pos.y - h, 1.0f, 0.0f, 0.0f,
    };

    tRect.vao = vao_new(5);
    vao_bind(tRect.vao);
    tRect.vbo = vbo_new(temp_vertices, 20);
    tRect.ebo = ebo_new(temp_indices, 6);

    vao_add_attribute(&tRect.vao, 3, GL_FLOAT);
    vao_add_attribute(&tRect.vao, 2, GL_FLOAT);
    vao_enable_attribute(0);
    vao_enable_attribute(1);

    tRect.texture = texture_new(textureName);

    vao_unbind();
    vbo_unbind();
    ebo_unbind();

    return tRect; 
}

void textured_rect_draw(textured_rect_t rect, window_t* window) {
    shader_set_current_shader(&window->shader, SHADER_TEXTURE);
    shader_set_mat4f(window->shader, rect.model, "uModel");
    glBindTexture(GL_TEXTURE_2D, rect.texture);
    vao_bind(rect.vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void textured_rect_move(textured_rect_t* rect, vec2s d) {
    vec3s movement = (vec3s){.x = d.x, .y = d.y, .z = 0};
    glm_translate(rect->model, movement.raw);
    rect->pos.x += d.x;
    rect->pos.y += d.y;
}

void textured_rect_set_pos(textured_rect_t* rect, vec2s d) {
    vec3s movement = (vec3s){.x = -rect->pos.x, .y = -rect->pos.y, .z = 0};
    glm_translate(rect->model, movement.raw);
    movement.x = d.x;
    movement.y = d.y;
    glm_translate(rect->model, movement.raw);
    rect->pos.x = d.x;
    rect->pos.y = d.y;
}
