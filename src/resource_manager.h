#pragma once

#include <unordered_map>
#include <variant>
#include "texture.h"

namespace StintaEngine {
    using namespace Types;

    struct TextureData {
        u8* data;
        i32 width, height, nChannels;
    };

    class ResourceManager {
        std::unordered_map<const char*, TextureData> resources;

    public:
        ResourceManager() = default;
        ~ResourceManager() = default;
        void LoadTexture(const char* name);
        TextureData GetTexture(const char* name);
    };
}
