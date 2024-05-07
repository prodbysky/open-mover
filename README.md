# Open Mover 
Game framework in C++ using OpenGL (GLAD GLFW CGLM)

## Running examples
```console
 $ make [Example name]
 $ ./bin/[Example name]
```

## Dependencies
 - Freetype2 [< 2.13]
 - Miniaudio
 - stb_image
 - GLAD [4.6 core]
 - GLM
 - GLFW
 - OpenGL [< 4.6]

## Features
 - Solid, and textured rectangles
 - Font rendering
 - Playing audio
 - Input management

## TODO:
 - Don't include dependencies directly so use packages from package managers (APT PACMAN...)
 - Compilation on Windows (horrible)
 - Move framework code to separate github repo (Not soon since it still experiencing rapid changes)
 - Remove debug messages from release builds
 - Optimize compile times (Now ~7 secs.)
