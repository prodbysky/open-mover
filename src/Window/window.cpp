#include "window.h"

#include "../Core/ZipLib.h"
#include "../Core/core.h"
#include "../Core/log.h"
#include "../Utilities/utilities.h"
#include "GLFW/glfw3.h"

#include <memory>
#include <ostream>
#include <sstream>

namespace ZipLib {
    Window::Window(u16 width, u16 height, const char* title, bool vSync) :
        window(nullptr), shader(nullptr) {
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

        ZipLib::Init(window);

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(Log::MessageCallback, nullptr);

        Log::Info("Succesfully initialized OpenGL, and created a window");

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

    Window::~Window() { glfwTerminate(); }

} // namespace ZipLib
