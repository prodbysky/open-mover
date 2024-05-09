#include "resource_manager.h"
#include "resources.h"
#include "stb_image.h"

namespace StintaEngine::Core {
    ResourceManager::ResourceManager() {
        textures = std::unordered_map<std::string, TextureData>();
        sounds = std::unordered_map<std::string, Sound>();
    }

    const TextureData& ResourceManager::LoadTexture(std::string name) {
        TextureData texture;
        stbi_set_flip_vertically_on_load(1);
        texture.data = stbi_load(name.c_str(), &texture.width, &texture.height, &texture.nChannels, 0);       
        textures.insert({name, texture});
        return textures.at(name);
    }

    const TextureData& ResourceManager::GetTexture(std::string name) {
        return textures.at(name);
    }

    TextureData& ResourceManager::GetMutTexture(std::string name) {
        return textures.at(name);
    }

    const Sound& ResourceManager::LoadSound(std::string name) {
        sounds.insert({name, Sound(name)});
        return sounds.at(name);
    }


    const Sound& ResourceManager::GetSound(std::string name) {
        return sounds.at(name);
    }

    Sound& ResourceManager::GetMutSound(std::string name) {
        return sounds.at(name);
    }
}
