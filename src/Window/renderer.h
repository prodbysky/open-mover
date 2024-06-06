#pragma once

#include <Core/shader.h>
#include <Core/texture.h>
#include <Core/vao.h>
#include <functional>
#include <memory>
#include <optional>

namespace ZipLib {
    struct DrawCall {
        Core::ShaderType type;
        Core::VAO vao;
        u32 vertex_count;
        bool using_indices;
        std::optional<Core::Texture> texture;
        std::function<void()> PreDraw;
        std::function<void()> SetUniforms;
    };

    class Renderer {
    public:
        Renderer();
        Renderer(u32 width, u32 height);
        void Draw(const DrawCall& draw_call);
        void Clear(u8 r, u8 g, u8 b, u8 a);

    public:
        std::unique_ptr<Core::Shader> shader;
    };
}; // namespace ZipLib
