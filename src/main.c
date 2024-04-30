#define GLFW_INCLUDE_NONE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "rect.h"
#include "input.h"
#include "window.h"
#include "shader.h"

typedef struct {
    vao_t vao;
    vbo_t vbo;
    ebo_t ebo;
    vec2s pos;
    f32 w, h;
    mat4 view;
    u32 texture;
} textured_rect_t;

textured_rect_t textured_rect_new(vec2s pos, f32 w, f32 h, const char* textureName) {
    textured_rect_t tRect;
    tRect.pos = pos;
    tRect.w = w;
    tRect.h = h;
    glm_mat4_identity(tRect.view);

    const u32 temp_indices[] = {0, 1, 2, 0, 2, 3};
    const f32 temp_vertices[] = {
        pos.x,     pos.y,     1.0f, 0.0f, 1.0f,
        pos.x + w, pos.y,     1.0f, 1.0f, 1.0f,
        pos.x + w, pos.y - h, 1.0f, 1.0f, 0.0f,
        pos.x,     pos.y - h, 1.0f, 0.0f, 0.0f,
    };

    tRect.vao = vao_new(5);
    vao_bind(tRect.vao);
    tRect.vbo = vbo_new(temp_vertices, 20);
    tRect.ebo = ebo_new(temp_indices, 6);

    vao_add_attribute(&tRect.vao, 3, GL_FLOAT);
    vao_add_attribute(&tRect.vao, 2, GL_FLOAT);
    vao_enable_attribute(0);
    vao_enable_attribute(1);

    glGenTextures(1, &tRect.texture);
    glBindTexture(GL_TEXTURE_2D, tRect.texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    i32 width, height, nChannels;
    stbi_set_flip_vertically_on_load(1);
    u8* data = stbi_load(textureName, &width, &height, &nChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); 
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        fprintf(stderr, "Failed to load texture: %s", textureName);
    }
    stbi_image_free(data);

    vao_unbind();
    vbo_unbind();
    ebo_unbind();

    return tRect; 
}

void textured_rect_draw(textured_rect_t rect, shader_t* shader) {
    shader_set_current_shader(shader, SHADER_TEXTURE);
    shader_set_mat4f(*shader, rect.view, "uView");
    glBindTexture(GL_TEXTURE_2D, rect.texture);
    vao_bind(rect.vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int main() {
    GLFWwindow* window = window_init(800, 800, "Hello world!");

    if (window == NULL) {
        return 0;
    }

    input_t input = input_new();
    input_setup(&input, window);

    shader_t shader = shader_new();
    shader_set_current_shader(&shader, SHADER_DEFAULT);
    shader_set_projection(shader, (vec2s){.x = 800, .y = 800}, (vec2s){.x = -1.5, .y = 1.5});
    shader_set_current_shader(&shader, SHADER_TEXTURE);
    shader_set_projection(shader, (vec2s){.x = 800, .y = 800}, (vec2s){.x = -1.5, .y = 1.5});

    rect_t rect = rect_new((vec2s){.x = 200, .y = 600}, 80, 80, (vec3s){.r = 1, .g = 1, .b = 1});
    textured_rect_t tRect = textured_rect_new((vec2s){.x = 300, .y = 600}, 80, 80, "assets/player.png");

    while (!window_should_close(window)) {
        window_clear(24, 24, 24, 255);
        rect_draw(rect, &shader);
        textured_rect_draw(tRect, &shader);
        window_swap(window);
    }

    glfwTerminate();
    return 0;
}
