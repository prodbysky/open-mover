#pragma once

#include "../Core/core.h"
#include "../Core/log.h"
#include "../Resource/resource_manager.h"

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

namespace ZipLib {
    void Init(GLFWwindow* window);

    inline static Core::Input Input;
    inline static Core::Audio Audio;
    inline static Core::ResourceManager ResourceManager;
    inline static Log log;
} // namespace ZipLib
