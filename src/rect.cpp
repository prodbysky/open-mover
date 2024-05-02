#include "rect.h"
#include "cglm/mat4.h"
#include "ebo.h"
#include "shader.h"
#include "vao.h"

Rect::Rect(vec2s pos, f32 w, f32 h, vec3s color) {
    this->pos = pos;
    this->w = w;
    this->h = h;
    this->color = color;
    glm_mat4_identity(model);

    u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
    f32 temp_vertices[] = {
        pos.x,     pos.y,     1.0f, 
        pos.x + w, pos.y,     1.0f,  
        pos.x + w, pos.y - h, 1.0f,  
        pos.x,     pos.y - h, 1.0f,  
    };

    vao = VAO(3);
    vbo = VBO(temp_vertices, 12);
    ebo = EBO(temp_indices, 6);

    vao.AddAttribute(3, GL_FLOAT);
    vao.Finalize(vbo, ebo);
}

void Rect::Move(vec3s move) {
    glm_translate(model, move.raw);
    pos.x += move.x;
    pos.y += move.y;
}

void Rect::Draw(Shader& shader) {
    shader.SetShader(SHADER_DEFAULT); 
    shader.SetUniform(color, "uColor");
    shader.SetUniform(model, "uModel");
    vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Rect::SetColor(vec3s color) {
    this->color = color;
}

void Rect::SetPos(vec2s move) {
    vec3s movement = (vec3s){.x = -pos.x, .y = -pos.y, .z = 0};
    glm_translate(model, movement.raw);
    movement.x = move.x;
    movement.y = move.y;
    glm_translate(model, movement.raw);
    pos.x = move.x;
    pos.y = move.y;
}
