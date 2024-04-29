#ifndef WINDOW_H
#define WINDOW_H

#include "types.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>

void resize_callback(GLFWwindow* window, i32 width, i32 height);
GLFWwindow* window_init(u16 width, u16 height, const char* title);
void window_clear(u16 r, u16 b, u16 g, u16 a);
void window_swap(GLFWwindow* window);
bool window_should_close(GLFWwindow* window);

#endif // WINDOW_H
