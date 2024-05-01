SRC = src/glad.c src/shader.c src/util.c src/rect.c src/window.c src/input.c src/vao.c src/vbo.c src/ebo.c src/texture.c src/textured_rect.c src/audio.c lib/miniaudio.o lib/stb_image.o

CPPFLAGS = -Llib/ -lglfw3 -lGL -lm -Iinclude/ -Wall -Werror -Wextra -ggdb

main: src/main.c $(SRC)
	g++ src/main.c -o main $(CPPFLAGS) $(SRC)
