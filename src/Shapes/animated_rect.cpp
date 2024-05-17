#include "animated_rect.h"

#include "../Resource/animation.h"
#include "glad/glad.h"
#include "rect.h"

namespace ZipLib::Shapes {
    AnimatedRect::AnimatedRect(glm::vec2 pos, f32 w, f32 h,
                               std::string frame_base_name, u32 frame_count,
                               GLenum texture_filter, GLenum image_type,
                               Core::ResourceManager& manager) :
        rect(pos, w, h),
        animation(frame_base_name, frame_count, GL_MIRRORED_REPEAT,
                  texture_filter, image_type, manager) {

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
    }
    void AnimatedRect::Draw(Core::Shader& shader) {
        shader.SetShader(Core::ShaderType::SHADER_TEXTURE);
        shader.SetUniform(rect.model, "uModel");
        animation.GetCurrentFrame().Bind();
        rect.vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        animation.GetCurrentFrame().Unbind();
    }

    void AnimatedRect::Move(glm::vec2 move) { rect.Move(move); }
    void AnimatedRect::SetPos(glm::vec2 move) { rect.SetPos(move); }
    void AnimatedRect::Advance() { animation.Advance(); }
}; // namespace ZipLib::Shapes
