CC = g++

CPPFLAGS = -Llib/ -lfreetype -lglfw3 -lGL -lm -lglm -Iinclude/ -Wall -Werror -Wextra -ggdb lib/miniaudio.o lib/stb_image.o lib/glad.o

SRC = src/Core/shader.cpp src/Utilities/util.cpp src/Shapes/rect.cpp src/Window/window.cpp \
      src/Core/input.cpp src/Core/vao.cpp src/Core/vbo.cpp src/Core/ebo.cpp src/Core/texture.cpp \
      src/Shapes/textured_rect.cpp src/Core/audio.cpp src/Resource/font.cpp src/Utilities/assert.cpp \
	  src/Resource/resource_manager.cpp src/Resource/resources.cpp src/UI/text.cpp

OBJ = $(SRC:.cpp=.o)

all: hello_window text_rendering playing_sounds rendering_textures top_down_movement flappy_bird

%.o : %.cpp, %.c
	$(CC) -c -o $@ $< $(CPPFLAGS)

hello_window: $(OBJ) src/Examples/hello_window.cpp
	$(CC) $(OBJ) src/Examples/hello_window.cpp -o bin/hello_window $(CPPFLAGS) 

text_rendering: $(OBJ) src/Examples/text_rendering.cpp 
	$(CC) $(OBJ) src/Examples/text_rendering.cpp -o bin/text_rendering $(CPPFLAGS) 

playing_sounds: $(OBJ) src/Examples/playing_sounds.cpp 
	$(CC) $(OBJ) src/Examples/playing_sounds.cpp -o bin/playing_sounds $(CPPFLAGS) 

rendering_textures: $(OBJ) src/Examples/rendering_textures.cpp
	$(CC) $(OBJ) src/Examples/rendering_textures.cpp -o bin/rendering_textures $(CPPFLAGS) 

top_down_movement: $(OBJ) src/Examples/top_down_movement.cpp
	$(CC) $(OBJ) src/Examples/top_down_movement.cpp -o bin/top_down_movement $(CPPFLAGS) 

flappy_bird: $(OBJ) src/Examples/flappy_bird.cpp
	$(CC) $(OBJ) src/Examples/flappy_bird.cpp -o bin/flappy_bird $(CPPFLAGS) 

clean:
	rm -f src/*.o bin/*
