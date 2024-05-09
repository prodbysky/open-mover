CC = g++

CPPFLAGS = -Llib/ -lfreetype -lglfw3 -lGL -lm -lglm -Iinclude/ -Wall -Werror -Wextra -ggdb lib/miniaudio.o lib/stb_image.o lib/glad.o

SRC = src/shader.cpp src/util.cpp src/rect.cpp src/window.cpp \
      src/input.cpp src/vao.cpp src/vbo.cpp src/ebo.cpp src/texture.cpp \
      src/textured_rect.cpp src/audio.cpp src/font.cpp src/font_system.cpp src/assert.cpp \
	  src/resource_manager.cpp

OBJ = $(SRC:.cpp=.o)

all: hello_window text_rendering playing_sounds rendering_textures

%.o : %.cpp, %.c
	$(CC) -c -o $@ $< $(CPPFLAGS)

hello_window: $(OBJ) src/hello_window.cpp
	$(CC) $(OBJ) src/hello_window.cpp -o bin/hello_window $(CPPFLAGS) 

text_rendering: $(OBJ) src/text_rendering.cpp 
	$(CC) $(OBJ) src/text_rendering.cpp -o bin/text_rendering $(CPPFLAGS) 

playing_sounds: $(OBJ) src/playing_sounds.cpp 
	$(CC) $(OBJ) src/playing_sounds.cpp -o bin/playing_sounds $(CPPFLAGS) 

rendering_textures: $(OBJ) src/rendering_textures.cpp
	$(CC) $(OBJ) src/rendering_textures.cpp -o bin/rendering_textures $(CPPFLAGS) 

clean:
	rm -f src/*.o bin/*
