# Open Mover 
OpenGL Game framework in C++
Highly inspired by Raylib (raysan5 <3)
As raysan5 said: "no fancy interface, no visual helpers, just coding in the most spartan-programmers way."

## Description
This is a game 2D game library that I make in interest
of learning C++ and OpenGL. I know it has some **interesing** design choices
but that is an expected side-effect of me being a relatively mediocre/ok developer
when making a not one off project.

## Example usage
```cpp
#include <Window/window.h>

i32 main() {
    ZipLib::Window window(800, 800, "Hello world!");

    while (!window.ShouldClose()) {
        window.renderer.Clear(24, 24, 24, 255);
        window.Swap();
    }
    return 0;
}
```
Opens a window and keeps a loop running until a close signal is sent by the user

Other examples are in the src/Examples directory

## Prerequisites
- C++17 compiler
- vcpkg
- ninja
- cmake
- A VGA that supports OpenGL 4.6 <= 

## Building
```console
 $ git clone https://github.com/prodbysky/open-mover
 $ cd open-mover
 $ mkdir build
 $ cd build
 $ cmake -DCMAKE_CXX_COMPILER=clang++ --preset=default ..
 $ ninja 
```

## Features
 - Solid, and textured rectangles
 - Font rendering
 - Playing audio
 - Input management

## References
 - [Learn OpenGL](learnopengl.com)
 - [Paroj OpenGL tutorial] (https://paroj.github.io/gltut/)

## Dependencies
 - Freetype2 [< 2.13]
 - Miniaudio
 - stb_image
 - stb_image_write
 - GLAD [4.6 core]
 - GLM
 - GLFW
 - OpenGL [< 4.6]
 - spdlog
