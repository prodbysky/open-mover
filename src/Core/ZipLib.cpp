#include "ZipLib.h"

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
