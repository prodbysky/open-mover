#include "ZipLib.h"

#include "../Core/core.h"
#include "../Core/log.h"

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

namespace ZipLib {
    void Init(GLFWwindow* window) {
        static bool initialized = false;
        if (!initialized) {
            ZipLib::Log::Init();
            ZipLib::Input.Setup(window);

            Log::Info("Succesfully initialized ZipLib subsystem");
            initialized = true;
        }
    }

} // namespace ZipLib
