#pragma once

#include <Core/audio.h>
#include <Core/input.h>
#include <Core/log.h>
#include <Resource/resource_manager.h>
#include <Utilities/util.h>

namespace ZipLib {
    void Init(GLFWwindow* window);

    inline static Core::Input Input;
    inline static Core::Audio Audio;
    inline static Core::ResourceManager ResourceManager;
    inline static Log Log;
    inline static Utilities::RNG Random;
} // namespace ZipLib
