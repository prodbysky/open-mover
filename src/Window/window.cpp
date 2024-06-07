#include "window.h"

#include <Core/ZipLib.h>
#include <Utilities/assert.h>
#include <glad/glad.h>
#include <stb_image_write.h>

namespace ZipLib {
    Window::Window(WindowConfig config) : window(nullptr) {
        Assert(config.width != 0, "Window width can't be 0");
        Assert(config.height != 0, "Window height can't be 0");
        Assert(config.title != nullptr, "Window title can't be null");

        // Initialize glfw, glad, and load opengl (4.6 core)
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Setup window
        window = glfwCreateWindow(config.width, config.height, config.title,
                                  nullptr, nullptr);
        Assert(window != nullptr, "Failed to create GLFW window!");
        glfwMakeContextCurrent(window);
        glfwSwapInterval(config.v_sync);

        gladLoadGL();
        glViewport(0, 0, config.width, config.height);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        ZipLib::Init(window);

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(Log::MessageCallback, nullptr);

        Log::Info("Succesfully initialized OpenGL, and created a window");

        renderer = Renderer(config.width, config.height);
        Log::Info("Succesfully initialized renderer");

        deltaTime    = 0;
        lastFrame    = 0;
        totalTime    = 0;
        this->width  = config.width;
        this->height = config.height;
    }

    void Window::SaveScreenshot(const char* file) {
        u8* pixels = new u8[3 * width * height];

        glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

        stbi_write_png(file, width, height, 3, pixels, 3);

        delete[] pixels;
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
