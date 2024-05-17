#include "../Shapes/textured_rect.h"

#include "../Core/texture.h"
#include "glad/glad.h"

#include <glm/ext/matrix_transform.hpp>

namespace ZipLib::Shapes {
    TexturedRect::TexturedRect(){};
    TexturedRect::TexturedRect(glm::vec2 pos, f32 w, f32 h,
                               const ZipLib::Core::TextureData& data,
                               GLenum texture_filter, GLenum image_type) :
        rect(pos, w, h) {
        u32 temp_indices[]  = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x, pos.y, 1.0f,      0.0f,      1.0f,      pos.x + w, pos.y,
            1.0f,  1.0f,  1.0f,      pos.x + w, pos.y - h, 1.0f,      1.0f,
            0.0f,  pos.x, pos.y - h, 1.0f,      0.0f,      0.0f,
        };

        rect.vbo = Core::VBO(temp_vertices, 20);
        rect.ebo = Core::EBO(temp_indices, 6);

        rect.vao.AddAttribute(3, GL_FLOAT);
        rect.vao.AddAttribute(2, GL_FLOAT);
        rect.vao.LinkVBOAndEBO(rect.vbo, rect.ebo);
        // Loads a glyph from a font
        texture =
            Core::Texture(data, GL_MIRRORED_REPEAT, texture_filter, image_type,
                          {}, Core::TextureType::TEXTURE_IMAGE);
    }

    void TexturedRect::Draw(Core::Shader& shader) const {
        shader.SetShader(Core::ShaderType::SHADER_TEXTURE);
        shader.SetUniform(rect.model, "uModel");
        texture.Bind();
        rect.vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        texture.Unbind();
    }

    void TexturedRect::Move(glm::vec2 move) {
        rect.Move(glm::vec3(move.x, move.y, 0));
    }

    void TexturedRect::SetPos(glm::vec2 move) { rect.SetPos(move); }
    void TexturedRect::Rotate(f32 degrees) { rect.Rotate(degrees); }
} // namespace ZipLib::Shapes
