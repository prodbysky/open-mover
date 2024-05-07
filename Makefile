CC = g++

CPPFLAGS = -Llib/ -lfreetype -lglfw3 -lGL -lm -lglm -Iinclude/ -Wall -Werror -Wextra -ggdb

SRC = src/glad.c src/shader.cpp src/util.cpp src/rect.cpp src/window.cpp \
      src/input.cpp src/vao.cpp src/vbo.cpp src/ebo.cpp src/texture.cpp \
      src/textured_rect.cpp src/audio.cpp src/font.cpp src/font_system.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = main

%.o : %.cpp, %.c
	$(CC) -c -o $@ $< $(CPPFLAGS)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) src/main.cpp -o $(TARGET) $(CPPFLAGS) lib/miniaudio.o lib/stb_image.o

clean:
	rm -f src/*.o $(TARGET)
