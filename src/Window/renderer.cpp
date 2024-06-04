#include "renderer.h"

#include <initializer_list>
#include <memory>

namespace ZipLib {
    Renderer::Renderer() : shader(nullptr) {}
    Renderer::Renderer(u32 width, u32 height) {
        shader = std::make_unique<Core::Shader>();
        for (auto type : {Core::ShaderType::SHADER_DEFAULT,
                          Core::ShaderType::SHADER_TEXTURE,
                          Core::ShaderType::SHADER_FONT}) {

            shader->SetShader(type);
            shader->SetProjection(glm::vec2(f32(width), f32(height)),
                                  glm::vec2(-1.5, 1.5));
        }
    }
    void Renderer::Clear(u8 r, u8 g, u8 b, u8 a) {
        glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}; // namespace ZipLib
