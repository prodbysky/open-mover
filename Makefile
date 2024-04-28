SRC = src/shader.c src/util.c

CFLAGS = -Llib/ -lglfw3 -lGLEW -lGL -lm -Iinclude/ -Wall -Werror -Wextra

main: src/main.c $(SRC)
	gcc src/main.c -o main $(CFLAGS) $(SRC)
