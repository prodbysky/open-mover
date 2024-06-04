#pragma once

#include "../Core/shader.h"

#include <memory>

namespace ZipLib {
    class Renderer {
    public:
        Renderer();
        Renderer(u32 width, u32 height);
        void Clear(u8 r, u8 g, u8 b, u8 a);

    private:
        std::unique_ptr<Core::Shader> shader;
    };
}; // namespace ZipLib
