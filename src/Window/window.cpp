#include "window.h"

#include "../Core/ZipLib.h"
#include "../Core/log.h"
#include "../Utilities/utilities.h"
#include "GLFW/glfw3.h"
#include "renderer.h"

namespace ZipLib {
    Window::Window(u16 width, u16 height, const char* title, bool vSync) :
        window(nullptr) {
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

        renderer = Renderer(width, height);
        Log::Info("Succesfully initialized renderer");

        deltaTime = 0;
        lastFrame = 0;
    }

    bool Window::ShouldClose() const { return glfwWindowShouldClose(window); }

    void Window::Swap() {
        f64 currentFrame = glfwGetTime();
        deltaTime        = currentFrame - lastFrame;
        lastFrame        = currentFrame;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    f64 Window::GetDeltaTime() const { return deltaTime; }

    f64 Window::GetFPS() const { return 1 / deltaTime; }

    f64 Window::GetTotalTime() const { return glfwGetTime(); }

    Window::~Window() { glfwTerminate(); }

} // namespace ZipLib
