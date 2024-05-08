#include "rect.h"
#include "ebo.h"
#include <glm/ext/matrix_transform.hpp>
#include "shader.h"
#include "vao.h"

namespace StintaEngine {
    Rect::Rect(glm::vec2 pos, f32 w, f32 h, glm::vec3 color) {
        this->pos = pos;
        this->w = w;
        this->h = h;
        this->color = color;
        model = glm::identity<glm::mat4>();

        u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x,     pos.y,     1.0f, 
            pos.x + w, pos.y,     1.0f,  
            pos.x + w, pos.y - h, 1.0f,  
            pos.x,     pos.y - h, 1.0f,  
        };

        vao = Core::VAO();
        vbo = Core::VBO(temp_vertices, 12);
        ebo = Core::EBO(temp_indices, 6);

        vao.AddAttribute(3, GL_FLOAT);
        vao.LinkVBOAndEBO(vbo, ebo);
    }

    void Rect::Move(glm::vec3 move) {
        model = glm::translate(model, move);
        pos.x += move.x;
        pos.y += move.y;
    }

    void Rect::Draw(Core::Shader& shader) const {
        shader.SetShader(Core::ShaderType::SHADER_DEFAULT); 
        shader.SetUniform(color, "uColor");
        shader.SetUniform(model, "uModel");
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void Rect::SetColor(glm::vec3 color) {
        this->color = color;
    }

    void Rect::SetPos(glm::vec2 move) {
        glm::vec3 movement(-pos.x, -pos.y, 0);
        model = glm::translate(model, movement);
        movement.x = move.x;
        movement.y = move.y;
        model = glm::translate(model, movement);
        pos.x = move.x;
        pos.y = move.y;
    }
}
