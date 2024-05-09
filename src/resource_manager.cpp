#include "resource_manager.h"
#include "stb_image.h"

namespace StintaEngine {
    using namespace Types;

    void ResourceManager::LoadTexture(const char* name) {
        TextureData texture;
        stbi_set_flip_vertically_on_load(1);
        texture.data = stbi_load(name, &texture.width, &texture.height, &texture.nChannels, 0);       
        resources[name] = texture;
    }

    TextureData ResourceManager::GetTexture(const char* name) {
        return resources.at(name);
    }
}
