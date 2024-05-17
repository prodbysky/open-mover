#include "animated_rect.h"

#include "../Resource/animation.h"
#include "glad/glad.h"
#include "rect.h"

namespace ZipLib::Shapes {
    AnimatedRect::AnimatedRect(glm::vec2 pos, f32 w, f32 h,
                               std::string frame_base_name, u32 frame_count,
                               GLenum texture_filter, GLenum image_type,
                               Core::ResourceManager& manager) :
        Rect(pos, w, h),
        animation(frame_base_name, frame_count, GL_MIRRORED_REPEAT,
                  texture_filter, image_type, manager) {

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
    void AnimatedRect::Draw(Core::Shader& shader) {
        shader.SetShader(Core::ShaderType::SHADER_TEXTURE);
        shader.SetUniform(model, "uModel");
        animation.GetCurrentFrame().Bind();
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        animation.GetCurrentFrame().Unbind();
    }

    void AnimatedRect::Advance() { animation.Advance(); }
}; // namespace ZipLib::Shapes
