#pragma once

#include <array>
#include <glad/glad.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <Utilities/types.h>
#include <glm/glm.hpp>
#include <vector>

namespace ZipLib::Core {
    // TODO: Add all GLFW keycodes
    enum class Key {
        W,
        A,
        S,
        D,
        Up,
        Down,
        Left,
        Right,

        MouseLeft,
        MouseRight,
    };

    i32 KeycodeToGLFW(Key key);

    struct InputRule {
        std::vector<Key> keys;

        template <class... Args> InputRule(Args... keys) {
            this->keys = {keys...};
        }
    };

    // Manages all input, provides api for getting mouse and keyboard state
    class Input {
    public:
        Input();
        // Setups all callbacks for getting input
        void Setup(GLFWwindow* window);
        bool InputRuleDown(InputRule rule);
        bool KeyDown(Key key) const;
        bool MouseKeyDown(Key button) const;
        glm::vec2 GetMousePos() const;

    private:
        inline static std::array<bool, 316> key_states;
        inline static std::array<bool, 2> mouse_state;
        inline static glm::vec2 mouse_pos;

    private:
        static void InputCallback(GLFWwindow* window, i32 key, i32 scancode,
                                  i32 action, i32 mods);
        static void CursorPositionCallback(GLFWwindow* window, double xpos,
                                           double ypos);
        static void MouseButtonCallback(GLFWwindow* window, int button,
                                        int action, int mods);
    };
} // namespace ZipLib::Core
