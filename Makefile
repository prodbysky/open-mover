SRC = src/glad.c src/shader.cpp src/util.cpp src/rect.cpp src/window.cpp src/input.cpp src/vao.cpp src/vbo.cpp src/ebo.cpp src/texture.cpp src/textured_rect.cpp src/audio.cpp lib/miniaudio.o lib/stb_image.o

CPPFLAGS = -Llib/ -lglfw3 -lGL -lm -Iinclude/ -Wall -Werror -Wextra -ggdb

main: src/main.cpp $(SRC)
	g++ src/main.cpp -o main $(CPPFLAGS) $(SRC)
