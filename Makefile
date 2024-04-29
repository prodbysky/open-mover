SRC = src/glad.c src/shader.c src/util.c src/rect.c src/window.c src/input.c src/vao.c src/vbo.c src/ebo.c

CFLAGS = -Llib/ -lglfw3 -lGL -lm -Iinclude/ -Wall -Werror -Wextra -ggdb

main: src/main.c $(SRC)
	gcc src/main.c -o main $(CFLAGS) $(SRC)
