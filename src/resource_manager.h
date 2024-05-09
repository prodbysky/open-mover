#pragma once

#include <unordered_map>
#include <string>

#include "resources.h"

namespace StintaEngine::Core {
    class ResourceManager {
    private:
        std::unordered_map<std::string, TextureData> textures;
        std::unordered_map<std::string, Sound> sounds;
    public:
        ResourceManager();
        ~ResourceManager() = default;
        const TextureData& LoadTexture(std::string name);
        const TextureData& GetTexture(std::string name);
        TextureData& GetMutTexture(std::string name);

        const Sound& LoadSound(std::string name);
        const Sound& GetSound(std::string name);
        Sound& GetMutSound(std::string name);
    };
}
