# Open Mover 
Game / Game framework in C using OpenGL (GLAD GLFW CGLM)

## Quick start
```console
  $ make main
  $ ./main
```

## Style
C files:
 - Function names: move_rect()
 - Variable / argument names: move_rect(int xDiffrence)
H files:
 - Header include guards

TODO:
 - Don't include dependencies directly so use packages from package managers (APT PACMAN...)
 - A generic renderer that takes a struct and a function that renders the object
 - Testing the functionality (Tests)
 - Text rendering
