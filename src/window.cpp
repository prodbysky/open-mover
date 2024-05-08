#include <cassert>
#include <glad/glad.h>

#include "window.h"
#include "GLFW/glfw3.h"
#include "assert.h"
#include "shader.h"
#include "types.h"
#include <iostream>
#include <memory>

namespace StintaEngine {
    Window::Window(u16 width, u16 height, const char* title, bool vSync) : window(nullptr), shader(nullptr), font_system(nullptr) {
        Assert(width != 0, "Window width can't be 0");
        Assert(height != 0, "Window height can't be 0");
        Assert(title != nullptr, "Window title can't be null");

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        Assert(window != nullptr, "Failed to create GLFW window!");

        glfwMakeContextCurrent(window);
        glfwSwapInterval(vSync);

        gladLoadGL();

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(MessageCallback, nullptr);

        glViewport(0, 0, width, height);
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

        input = Core::Input();
        input.Setup(window);
        audio = Core::Audio();
        font_system = std::make_unique<Core::FontSystem>(); 

        shader = std::make_unique<Core::Shader>();
        shader->SetShader(Core::ShaderType::SHADER_DEFAULT);
        shader->SetProjection(glm::vec2(f32(width), f32(height)), glm::vec2(-1.5, 1.5));
        shader->SetShader(Core::ShaderType::SHADER_TEXTURE);
        shader->SetProjection(glm::vec2(f32(width), f32(height)), glm::vec2(-1.5, 1.5));
        shader->SetShader(Core::ShaderType::SHADER_FONT);
        shader->SetProjection(glm::vec2(f32(width), f32(height)), glm::vec2(-1.5, 1.5));

        deltaTime = 0;
        lastFrame = 0;
    }

    bool Window::ShouldClose() {
        return glfwWindowShouldClose(window);
    }

    void Window::Swap() {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::Clear(u16 r, u16 b, u16 g, u16 a) {
        f64 currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    f64 Window::GetDeltaTime() {
        return deltaTime;
    }

    f64 Window::GetTotalTime() {
        return glfwGetTime();
    }

    Window::~Window() {
        glfwTerminate();
    }

    void Window::MessageCallback(GLenum src, GLenum type, GLuint id, GLenum severity, GLsizei len, GLchar const* message, void const* user_param) {
        (void) user_param;
        (void) len;
        auto const src_str = [src]() {
            switch (src) {
                case GL_DEBUG_SOURCE_API: return "API";
                case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "WINDOW SYSTEM";
                case GL_DEBUG_SOURCE_SHADER_COMPILER: return "SHADER COMPILER";
                case GL_DEBUG_SOURCE_THIRD_PARTY: return "THIRD PARTY";
                case GL_DEBUG_SOURCE_APPLICATION: return "APPLICATION";
                case GL_DEBUG_SOURCE_OTHER: return "OTHER";
            }
            return "UNKNOWN";
        }();

        auto const type_str = [type]() {
            switch (type) {
                case GL_DEBUG_TYPE_ERROR: return "ERROR";
                case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED_BEHAVIOR";
                case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED_BEHAVIOR";
                case GL_DEBUG_TYPE_PORTABILITY: return "PORTABILITY";
                case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
                case GL_DEBUG_TYPE_MARKER: return "MARKER";
                case GL_DEBUG_TYPE_OTHER: return "OTHER";
            }
            return "UNKNOWN";
        }();

        auto const severity_str = [severity]() {
            switch (severity) {
                case GL_DEBUG_SEVERITY_NOTIFICATION: return "NOTIFICATION";
                case GL_DEBUG_SEVERITY_LOW: return "LOW";
                case GL_DEBUG_SEVERITY_MEDIUM: return "MEDIUM";
                case GL_DEBUG_SEVERITY_HIGH: return "HIGH";
            }
            return "UNKNOWN";
        }();
        std::cerr << src_str << ", " << type_str << ", " << severity_str << ", " << id << ": " << message << '\n';
    }
}
