#include "resource_manager.h"
#include "freetype/freetype.h"
#include "stb_image.h"
#include <unordered_map>
#include "../Utilities/assert.h"

namespace ZipLib::Core {
    ResourceManager::ResourceManager() {
        textures = std::unordered_map<std::string, TextureData>();
        sounds = std::unordered_map<std::string, Sound>();
        fonts = std::unordered_map<std::string, Font>();
        FT_Init_FreeType(&freetype);
    }

    const TextureData& ResourceManager::LoadTexture(std::string name) {
        TextureData texture;
        stbi_set_flip_vertically_on_load(1);
        texture.data = stbi_load(name.c_str(), &texture.width, &texture.height, &texture.nChannels, 0);       
        Assert(texture.data != nullptr, "Failed to load texture");
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

    const Font& ResourceManager::LoadFont(std::string name, u16 height) {
        fonts.insert({name, Font(freetype, name.c_str(), height)});
        return fonts.at(name);
    }

    const Font& ResourceManager::GetFont(std::string name) {
        return fonts.at(name);
    }

    Font& ResourceManager::GetMutFont(std::string name) {
        return fonts.at(name);
    }
}
