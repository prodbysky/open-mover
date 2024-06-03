#include "log.h"

#include "spdlog/sinks/stdout_color_sinks-inl.h"

namespace ZipLib {
    void Log::Init() {
        Log::initialized = true;
        Log::logger      = spdlog::stdout_color_mt("ZipLib");
    }

    void Log::SetLevel(spdlog::level::level_enum level) {
        Log::logger->set_level(level);
    }

} // namespace ZipLib
