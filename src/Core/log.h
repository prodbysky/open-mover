#pragma once

#include "spdlog/common.h"
#include "spdlog/logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace ZipLib {
    class Log {
    public:
        Log() = delete;

        static void Init();

        template <class... Args> static void Trace(Args... args) {
            if (!Log::initialized)
                Log::Init();
            Log::logger->trace(args...);
        }

        template <class... Args> static void Debug(Args... args) {
            if (!Log::initialized)
                Log::Init();
            Log::logger->debug(args...);
        }

        template <class... Args> static void Info(Args... args) {
            if (!Log::initialized)
                Log::Init();
            Log::logger->info(args...);
        }

        template <class... Args> static void Warn(Args... args) {
            if (!Log::initialized)
                Log::Init();
            Log::logger->warn(args...);
        }

        template <class... Args> static void Error(Args... args) {
            if (!Log::initialized)
                Log::Init();
            Log::logger->error(args...);
        }

        template <class... Args> static void Critical(Args... args) {
            if (!Log::initialized)
                Log::Init();
            Log::logger->critical(args...);
        }

        static void SetLevel(spdlog::level::level_enum level);

    private:
        static inline bool initialized = false;
        static inline std::shared_ptr<spdlog::logger> logger;
    };
} // namespace ZipLib
