CC = g++

CPPFLAGS = -Llib/ -lfreetype -lglfw3 -lGL -lm -lglm -Iinclude/ -Wall -Werror -Wextra -O3 lib/miniaudio.o lib/stb_image.o lib/glad.o

SRC = src/Core/shader.cpp src/Utilities/util.cpp src/Shapes/rect.cpp src/Shapes/colored_rect.cpp src/Window/window.cpp \
      src/Core/input.cpp src/Core/vao.cpp src/Core/vbo.cpp src/Core/ebo.cpp src/Core/texture.cpp \
      src/Shapes/textured_rect.cpp src/Core/audio.cpp src/Utilities/assert.cpp \
	  src/Resource/resource_manager.cpp src/Resource/resources.cpp src/UI/text.cpp src/Resource/texture_data.cpp

OBJ = $(SRC:.cpp=.o)

all: hello_window text_rendering playing_sounds rendering_textures top_down_movement flappy_bird point_vs_rect aabb_collision

%.o : %.cpp, %.c
	$(CC) -c -o $@ $< $(CPPFLAGS)

hello_window: $(OBJ) src/Examples/hello_window.cpp
	$(CC) $(OBJ) src/Examples/hello_window.cpp -o bin/hello_window $(CPPFLAGS) 

text_rendering: $(OBJ) src/Examples/text_rendering.cpp 
	$(shell) $(CC) $(OBJ) src/Examples/text_rendering.cpp -o bin/text_rendering $(CPPFLAGS) 

playing_sounds: $(OBJ) src/Examples/playing_sounds.cpp 
	$(shell) $(CC) $(OBJ) src/Examples/playing_sounds.cpp -o bin/playing_sounds $(CPPFLAGS) 

rendering_textures: $(OBJ) src/Examples/rendering_textures.cpp
	$(shell) $(CC) $(OBJ) src/Examples/rendering_textures.cpp -o bin/rendering_textures $(CPPFLAGS) 

top_down_movement: $(OBJ) src/Examples/top_down_movement.cpp
	$(shell) $(CC) $(OBJ) src/Examples/top_down_movement.cpp -o bin/top_down_movement $(CPPFLAGS) 

flappy_bird: $(OBJ) src/Examples/flappy_bird.cpp
	$(shell) $(CC) $(OBJ) src/Examples/flappy_bird.cpp -o bin/flappy_bird $(CPPFLAGS) 

point_vs_rect: $(OBJ) src/Examples/point_vs_rect.cpp
	$(shell) $(CC) $(OBJ) src/Examples/point_vs_rect.cpp -o bin/point_vs_rect $(CPPFLAGS) 

aabb_collision: $(OBJ) src/Examples/aabb_collision.cpp
	$(shell) $(CC) $(OBJ) src/Examples/aabb_collision.cpp -o bin/aabb_collision $(CPPFLAGS) 

clean:
	rm -f src/**/*.o bin/*
