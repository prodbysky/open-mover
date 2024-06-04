#include "animated_rect.h"

#include "../Core/ZipLib.h"
#include "../Resource/animation.h"
#include "glad/glad.h"
#include "rect.h"

#include <memory>

namespace ZipLib::Shapes {
    AnimatedRect::AnimatedRect(glm::vec2 pos, f32 w, f32 h,
                               std::string frame_base_name, u32 frame_count,
                               GLenum texture_filter, GLenum image_type) :
        Rect(pos, w, h),
        animation(frame_base_name, frame_count, GL_MIRRORED_REPEAT,
                  texture_filter, image_type, ZipLib::ResourceManager) {

        u32 temp_indices[]  = {0, 1, 2, 0, 2, 3};
        f32 temp_vertices[] = {
            pos.x, pos.y, 1.0f,      0.0f,      1.0f,      pos.x + w, pos.y,
            1.0f,  1.0f,  1.0f,      pos.x + w, pos.y - h, 1.0f,      1.0f,
            0.0f,  pos.x, pos.y - h, 1.0f,      0.0f,      0.0f,
        };

        vbo = Core::VBO(temp_vertices, 20);
        ebo = Core::EBO(temp_indices, 6);

        vao.AddAttribute(3, GL_FLOAT);
        vao.AddAttribute(2, GL_FLOAT);
        vao.LinkVBOAndEBO(vbo, ebo);
    }
    void AnimatedRect::Draw(Renderer& renderer) {
        draw_call = {
            .type          = Core::ShaderType::SHADER_TEXTURE,
            .vao           = vao,
            .vertex_count  = 6,
            .using_indices = true,
            .texture       = {},
            .PreDraw       = []() {},
            .SetUniforms =
                [this, &renderer]() {
                    renderer.shader->SetUniform(model, "uModel");
                },
        };

        draw_call.texture = animation.GetCurrentFrame();
        renderer.Draw(draw_call);
    }

    void AnimatedRect::Advance() { animation.Advance(); }
}; // namespace ZipLib::Shapes
