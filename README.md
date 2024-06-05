# Open Mover 
Game framework in C++ using OpenGL (GLAD GLFW GLM)

## Running examples
```console
 $ mkdir build
 $ cd build
 $ PARALLEL_LEVEL=7 cmake -G Ninja -DCMAKE_CXX_COMPILER=clang++ ..
 $ ninja 
```

## List of example names
 - hello_window
 - text_rendering
 - playing_sounds
 - rendering_textures
 - top_down_movement
 - flappy_bird
 - point_vs_rect
 - aabb_collision

## Features
 - Solid, and textured rectangles
 - Font rendering
 - Playing audio
 - Input management

## References
 - [Learn OpenGL](learnopengl.com)
 - [Paroj OpenGL tutorial (https://paroj.github.io/gltut/)

## Dependencies
 - Freetype2 [< 2.13]
 - Miniaudio
 - stb_image
 - GLAD [4.6 core]
 - GLM
 - GLFW
 - OpenGL [< 4.6]

## TODO:
 - Remove debug messages from release builds
 - More examples
 - Lighting
 - Camera transforming
