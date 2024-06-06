#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace ZipLib {
    Log::Log() {}
    void Log::Init() {
        static bool initialized = false;
        if (!initialized) {
            Log::logger = spdlog::stdout_color_mt("ZipLib");
        }
        initialized = true;
    }

    void Log::SetLevel(spdlog::level::level_enum level) {
        Log::logger->set_level(level);
    }

} // namespace ZipLib
