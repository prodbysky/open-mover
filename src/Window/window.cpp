#include "window.h"

#include "../Core/core.h"
#include "../Utilities/utilities.h"
#include "GLFW/glfw3.h"
#include "freetype/freetype.h"

#include <iostream>
#include <memory>

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

        // Setup debug loggin
        if (debug) {
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(MessageCallback, nullptr);
        }

        input.Setup(window);
        shader = std::make_unique<Core::Shader>();

        for (auto type : {Core::ShaderType::SHADER_DEFAULT,
                          Core::ShaderType::SHADER_TEXTURE,
                          Core::ShaderType::SHADER_FONT}) {

            shader->SetShader(type);
            shader->SetProjection(glm::vec2(f32(width), f32(height)),
                                  glm::vec2(-1.5, 1.5));
        }

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
        auto const src_str = [src]() {
            switch (src) {
            case GL_DEBUG_SOURCE_API:
                return "API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                return "WINDOW SYSTEM";
            case GL_DEBUG_SOURCE_SHADER_COMPILER:
                return "SHADER COMPILER";
            case GL_DEBUG_SOURCE_THIRD_PARTY:
                return "THIRD PARTY";
            case GL_DEBUG_SOURCE_APPLICATION:
                return "APPLICATION";
            case GL_DEBUG_SOURCE_OTHER:
                return "OTHER";
            }
            return "UNKNOWN";
        }();

        auto const type_str = [type]() {
            switch (type) {
            case GL_DEBUG_TYPE_ERROR:
                return "ERROR";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                return "DEPRECATED_BEHAVIOR";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                return "UNDEFINED_BEHAVIOR";
            case GL_DEBUG_TYPE_PORTABILITY:
                return "PORTABILITY";
            case GL_DEBUG_TYPE_PERFORMANCE:
                return "PERFORMANCE";
            case GL_DEBUG_TYPE_MARKER:
                return "MARKER";
            case GL_DEBUG_TYPE_OTHER:
                return "OTHER";
            }
            return "UNKNOWN";
        }();

        auto const severity_str = [severity]() {
            switch (severity) {
            case GL_DEBUG_SEVERITY_NOTIFICATION:
                return "NOTIFICATION";
            case GL_DEBUG_SEVERITY_LOW:
                return "LOW";
            case GL_DEBUG_SEVERITY_MEDIUM:
                return "MEDIUM";
            case GL_DEBUG_SEVERITY_HIGH:
                return "HIGH";
            }
            return "UNKNOWN";
        }();
        std::cerr << src_str << ", " << type_str << ", " << severity_str << ", "
                  << id << ": " << message << '\n';
    }
} // namespace ZipLib
