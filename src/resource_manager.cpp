#include "resource_manager.h"
#include "stb_image.h"

namespace StintaEngine::Core {

    TextureData::~TextureData() {
        stbi_image_free(data);
    }

    ResourceManager::ResourceManager() {
        resources = std::unordered_map<std::string, TextureData>();
    }

    const TextureData& ResourceManager::LoadTexture(std::string name) {
        TextureData texture;
        stbi_set_flip_vertically_on_load(1);
        texture.data = stbi_load(name.c_str(), &texture.width, &texture.height, &texture.nChannels, 0);       
        resources.insert({name, texture});
        return resources.at(name);
    }

    const TextureData& ResourceManager::GetTexture(std::string name) {
        return resources.at(name);
    }


    TextureData& ResourceManager::GetMutTexture(std::string name) {
        return resources.at(name);
    }
}
