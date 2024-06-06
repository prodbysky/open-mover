#include <Shapes/textured_rect.h>

namespace ZipLib::Shapes {
    TexturedRect::TexturedRect(){};
    TexturedRect::TexturedRect(glm::vec2 pos, f32 w, f32 h,
                               const ZipLib::Core::TextureData& data,
                               GLenum texture_filter, GLenum image_type) :
        Rect(pos, w, h) {
        u32 temp_indices[]  = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x, pos.y, 1.0f,      0.0f,      1.0f,      pos.x + w, pos.y,
            1.0f,  1.0f,  1.0f,      pos.x + w, pos.y - h, 1.0f,      1.0f,
            0.0f,  pos.x, pos.y - h, 1.0f,      0.0f,      0.0f,
        };

        vbo = Core::VBO(temp_vertices, 20);
        ebo = Core::EBO(temp_indices, 6);

        vao.AddAttribute<float>(3);
        vao.AddAttribute<float>(2);
        vao.LinkVBOAndEBO(vbo, ebo);
        // Loads a glyph from a font
        texture =
            Core::Texture(data, GL_MIRRORED_REPEAT, texture_filter, image_type,
                          {}, Core::TextureType::TEXTURE_IMAGE);
    }

    void TexturedRect::Draw(Renderer& renderer) {
        draw_call = {
            .type          = Core::ShaderType::SHADER_TEXTURE,
            .vao           = vao,
            .vertex_count  = 6,
            .using_indices = true,
            .texture       = texture,
            .PreDraw       = []() {},
            .SetUniforms =
                [this, &renderer]() {
                    renderer.shader->SetUniform(model, "uModel");
                },
        };
        renderer.Draw(draw_call);
    }
} // namespace ZipLib::Shapes
