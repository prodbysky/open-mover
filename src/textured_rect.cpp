#include "textured_rect.h"
#include "cglm/mat4.h"
#include "shader.h"
#include "texture.h"
#include <memory>

TexturedRect::TexturedRect(vec2s pos, f32 w, f32 h, const char* textureName) {
    this->pos = pos;
    this->w = w;
    this->h = h;
    glm_mat4_identity(model);

    u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
    f32 temp_vertices[] = {
        pos.x,     pos.y,     1.0f, 0.0f, 1.0f,
        pos.x + w, pos.y,     1.0f, 1.0f, 1.0f,
        pos.x + w, pos.y - h, 1.0f, 1.0f, 0.0f,
        pos.x,     pos.y - h, 1.0f, 0.0f, 0.0f,
    };

    vao = VAO(5);
    vao.Bind();
    vbo = VBO(temp_vertices, 20);
    ebo = EBO(temp_indices, 6);

    vao.AddAttribute(3, GL_FLOAT);
    vao.AddAttribute(2, GL_FLOAT);
    vao.EnableAttribute(0);
    vao.EnableAttribute(1);

    texture = Texture(textureName);
    
    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();
}

void TexturedRect::Draw(std::unique_ptr<Shader>& shader) {
    shader->SetShader(SHADER_TEXTURE);
    shader->SetUniform(model, "uModel");
    texture.Bind();
    vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void TexturedRect::Move(vec2s move) {
    vec3s movement = (vec3s){.x = move.x, .y = move.y, .z = 0};
    glm_translate(model, movement.raw);
    pos.x += move.x;
    pos.y += move.y;
}

void TexturedRect::SetPos(vec2s move) {
    vec3s movement = (vec3s){.x = -pos.x, .y = -pos.y, .z = 0};
    glm_translate(model, movement.raw);
    movement.x = move.x;
    movement.y = move.y;
    glm_translate(model, movement.raw);
    pos.x = move.x;
    pos.y = move.y;
}

