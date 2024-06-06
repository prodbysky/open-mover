cmake_minimum_required(VERSION 3.10)
project(ziplib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -ggdb -ftime-trace")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

find_package(spdlog CONFIG REQUIRED)
find_package(Freetype CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)

# Define include directories
# include_directories(include)
include_directories(include ${GLM_INCLUDE_DIRS} ${SPDLOG_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIRS})

# Define library directories
# link_directories(lib)

# Recursively find all source files in src/, excluding src/Examples/**
file(
  GLOB_RECURSE SRC_FILES
  RELATIVE ${CMAKE_SOURCE_DIR}
  src/**/*.cpp)
file(
  GLOB_RECURSE EXAMPLE_FILES
  RELATIVE ${CMAKE_SOURCE_DIR}
  src/Examples/*.cpp)
list(REMOVE_ITEM SRC_FILES ${EXAMPLE_FILES})

# Define the object files
set(OBJ lib/miniaudio.o lib/stb_image.o lib/glad.o)
# Create a static library for ZipLib with all source files except
# src/Examples/**
add_library(ZipLib STATIC ${SRC_FILES} ${OBJ})

target_link_libraries(ZipLib ${GLFW_LIBRARIES})

# Link the necessary libraries to ZipLib
target_link_libraries(ZipLib Freetype::Freetype glfw OpenGL::GL m glm::glm spdlog::spdlog)


# Create a function to add examples
function(add_example name)
  add_executable(${name} src/Examples/${name}.cpp ${OBJ})
  target_link_libraries(${name} ZipLib)
  add_dependencies(${name} copy_assets)
endfunction()

# Add examples
add_example(hello_window)
add_example(text_rendering)
add_example(playing_sounds)
add_example(rendering_textures)
add_example(top_down_movement)
add_example(point_vs_rect)
add_example(aabb_collision)
add_example(delayed_sound)
add_example(fps_display)
add_example(animation_example)

# Copy assets directory to the build directory
add_custom_target(
  copy_assets ALL COMMAND ${CMAKE_COMMAND} -E copy_directory
                          ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)

# Add a clean target
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "bin")
