#pragma once

#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <sstream>

namespace ZipLib {
    class Log {
    public:
        Log();

        static void Init();

        template <class... Args> static void Trace(Args... args) {
            Log::Init();
            Log::logger->trace(args...);
        }

        template <class... Args> static void Debug(Args... args) {
            Log::Init();
            Log::logger->debug(args...);
        }

        template <class... Args> static void Info(Args... args) {
            Log::Init();
            Log::logger->info(args...);
        }

        template <class... Args> static void Warn(Args... args) {
            Log::Init();
            Log::logger->warn(args...);
        }

        template <class... Args> static void Error(Args... args) {
            Log::Init();
            Log::logger->error(args...);
        }

        template <class... Args> static void Critical(Args... args) {
            Log::Init();
            Log::logger->critical(args...);
        }

        static void SetLevel(spdlog::level::level_enum level);

        static void MessageCallback(GLenum src, GLenum type, GLuint id,
                                    GLenum severity, GLsizei len,
                                    GLchar const* message,
                                    void const* user_param) {
            (void) user_param;
            (void) len;
            (void) id;
            auto const src_str = [src]() {
                switch (src) {
                case GL_DEBUG_SOURCE_API:
                    return "API";
                case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                    return "Window system";
                case GL_DEBUG_SOURCE_SHADER_COMPILER:
                    return "Shader compiler";
                case GL_DEBUG_SOURCE_THIRD_PARTY:
                    return "Third party";
                case GL_DEBUG_SOURCE_APPLICATION:
                    return "Application";
                case GL_DEBUG_SOURCE_OTHER:
                    return "Other";
                }
                return "Unknown";
            }();

            auto const type_str = [type]() {
                switch (type) {
                case GL_DEBUG_TYPE_ERROR:
                    return "Error";
                case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                    return "Deprecated";
                case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                    return "Undefined";
                case GL_DEBUG_TYPE_PORTABILITY:
                    return "Portability";
                case GL_DEBUG_TYPE_PERFORMANCE:
                    return "Performance";
                case GL_DEBUG_TYPE_MARKER:
                    return "Marker";
                case GL_DEBUG_TYPE_OTHER:
                    return "Other";
                }
                return "Unknown";
            }();

            std::stringstream ss;
            ss << src_str << " " << type_str << " " << message;

            [severity, &ss]() {
                switch (severity) {
                case GL_DEBUG_SEVERITY_NOTIFICATION:
                    Log::Trace(ss.str());
                    break;
                case GL_DEBUG_SEVERITY_LOW:
                    Log::Info(ss.str());
                    break;
                case GL_DEBUG_SEVERITY_MEDIUM:
                    Log::Warn(ss.str());
                    break;
                case GL_DEBUG_SEVERITY_HIGH:
                    Log::Critical(ss.str());
                    break;
                default:
                    return;
                }
            }();
        }

    private:
        static inline std::shared_ptr<spdlog::logger> logger;
    };
} // namespace ZipLib
