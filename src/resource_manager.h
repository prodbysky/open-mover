#pragma once

#include <unordered_map>
#include <variant>
#include <string>
#include "input.h"

namespace StintaEngine::Core {
    using namespace StintaEngine::Types;

    struct TextureData {
        u8* data;
        i32 width, height, nChannels;
        ~TextureData();
    };

    class ResourceManager {
        std::unordered_map<std::string, TextureData> resources;

    public:
        ResourceManager();
        ~ResourceManager() = default;
        const TextureData& LoadTexture(std::string name);
        // Get the texture with a const reference
        const TextureData& GetTexture(std::string name);
        TextureData& GetMutTexture(std::string name);
    };
}
