#include <glm/ext/matrix_transform.hpp>
#include "../Shapes/textured_rect.h"
#include "../Core/texture.h"
#include "glad/glad.h"

namespace StintaEngine::Shapes {
    TexturedRect::TexturedRect(glm::vec2 pos, f32 w, f32 h, const StintaEngine::Core::TextureData& data, GLenum texture_filter, GLenum image_type) {
        this->pos = pos;
        this->w = w;
        this->h = h;
        model = glm::identity<glm::mat4>();

        u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x,     pos.y,     1.0f, 0.0f, 1.0f,
            pos.x + w, pos.y,     1.0f, 1.0f, 1.0f,
            pos.x + w, pos.y - h, 1.0f, 1.0f, 0.0f,
            pos.x,     pos.y - h, 1.0f, 0.0f, 0.0f,
        };

        vao = Core::VAO();
        vbo = Core::VBO(temp_vertices, 20);
        ebo = Core::EBO(temp_indices, 6);

        vao.AddAttribute(3, GL_FLOAT);
        vao.AddAttribute(2, GL_FLOAT);
        vao.LinkVBOAndEBO(vbo, ebo);

        // Loads a glyph from a font
        texture = Core::Texture(data, GL_MIRRORED_REPEAT, texture_filter, image_type, {}, Core::TextureType::TEXTURE_IMAGE);
    }

    void TexturedRect::Draw(Core::Shader& shader) const {
        shader.SetShader(Core::ShaderType::SHADER_TEXTURE);
        shader.SetUniform(model, "uModel");
        texture.Bind();
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        texture.Unbind();
    }

    void TexturedRect::Move(glm::vec2 move) {
        glm::vec3 movement(move.x, move.y, 0);
        model = glm::translate(model, movement);
        pos.x += move.x;
        pos.y += move.y;
    }

    void TexturedRect::SetPos(glm::vec2 move) {
        glm::vec3 movement(-pos.x, -pos.y, 0);
        model = glm::translate(model, movement);
        movement.x = move.x;
        movement.y = move.y;
        model = glm::translate(model, movement);
        pos.x = move.x;
        pos.y = move.y;
    }
}
