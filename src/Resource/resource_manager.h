#pragma once

#include "../Resource/texture_data.h"
#include "resources.h"

#include <map>
#include <string>

namespace ZipLib::Core {
    class ResourceManager {
    private:
        std::map<std::string, TextureData> textures;
        std::map<std::string, Font> fonts;
        FT_Library freetype;

    public:
        ResourceManager();
        ~ResourceManager() = default;
        const TextureData& LoadTexture(std::string name);
        const TextureData& GetTexture(std::string name);
        TextureData& GetMutTexture(std::string name);

        const Font& LoadFont(std::string name, u16 height);
        const Font& GetFont(std::string name);
        Font& GetMutFont(std::string name);
    };
} // namespace ZipLib::Core
