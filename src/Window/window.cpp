#include "window.h"

#include "../Core/core.h"
#include "../Core/log.h"
#include "../Utilities/utilities.h"
#include "GLFW/glfw3.h"
#include "freetype/freetype.h"

#include <memory>
#include <ostream>
#include <sstream>

namespace ZipLib {
    Window::Window(u16 width, u16 height, const char* title, bool vSync,
                   bool debug) : window(nullptr), shader(nullptr) {
        Assert(width != 0, "Window width can't be 0");
        Assert(height != 0, "Window height can't be 0");
        Assert(title != nullptr, "Window title can't be null");

        // Initialize glfw, glad, and load opengl (4.6 core)
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Setup window
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        Assert(window != nullptr, "Failed to create GLFW window!");
        glfwMakeContextCurrent(window);
        glfwSwapInterval(vSync);

        gladLoadGL();
        glViewport(0, 0, width, height);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        Log::Info("Succesfully initialized OpenGL, and created a window");

        // Setup debug loggin
        if (debug) {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(MessageCallback, nullptr);
        }

        input.Setup(window);
        shader = std::make_shared<Core::Shader>();

        for (auto type : {Core::ShaderType::SHADER_DEFAULT,
                          Core::ShaderType::SHADER_TEXTURE,
                          Core::ShaderType::SHADER_FONT}) {

            shader->SetShader(type);
            shader->SetProjection(glm::vec2(f32(width), f32(height)),
                                  glm::vec2(-1.5, 1.5));
        }

        Log::Info("Succesfully initialized shaders");

        deltaTime = 0;
        lastFrame = 0;
        FT_Init_FreeType(&freetype);
    }

    bool Window::ShouldClose() const { return glfwWindowShouldClose(window); }

    void Window::Swap() const {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::Clear(u8 r, u8 b, u8 g, u8 a) {
        f64 currentFrame = glfwGetTime();
        deltaTime        = currentFrame - lastFrame;
        lastFrame        = currentFrame;

        glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    f64 Window::GetDeltaTime() const { return deltaTime; }

    f64 Window::GetFPS() const { return 1 / deltaTime; }

    f64 Window::GetTotalTime() const { return glfwGetTime(); }

    Window::~Window() {
        FT_Done_FreeType(freetype);
        glfwTerminate();
    }

    void Window::MessageCallback(GLenum src, GLenum type, GLuint id,
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
} // namespace ZipLib
