main: src/main.c
	gcc src/main.c -o main -Llib/ -lglfw3 -lGLEW -lGL -lm -Iinclude/
