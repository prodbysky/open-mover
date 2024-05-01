#pragma once

#include <cglm/cglm.h>
#include <cglm/struct.h>

#include "types.h"

typedef struct {
    u32 defaultID;
    u32 textureID;
    u32 currentID;
} shader_t;

typedef enum {
    SHADER_DEFAULT,
    SHADER_TEXTURE,
} shader_type_e;

shader_t shader_new();
void shader_set_projection(shader_t shader, vec2s size, vec2s zBounds);
void shader_use(shader_t shader);
void shader_set_mat4f(shader_t shader, mat4 data, const char* name);
void shader_set_vec3f(shader_t shader, vec3s data, const char* name);
void shader_set_current_shader(shader_t* shader, shader_type_e type);
