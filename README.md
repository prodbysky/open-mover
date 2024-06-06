# Open Mover 
Game framework in C++ using OpenGL (GLAD GLFW GLM)

## Running examples
```console
 $ mkdir build
 $ cd build
 $ cmake -DCMAKE_CXX_COMPILER=clang++ --preset=default ..
 $ ninja 
```

## List of example names
 - aabb_collision
 - animation_example
 - delayed_sound
 - fps_display
 - hello_window
 - playing_sounds
 - point_vs_rect
 - rendering_textures
 - text_rendering
 - top_down_movement

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
 - GLAD [4.6 core]
 - GLM
 - GLFW
 - OpenGL [< 4.6]
 - spdlog

## TODO:
 - Remove debug messages from release builds
 - More examples
 - Lighting
 - Camera transforming
