#ifndef SHADER_H
#define SHADER_H

#include <cglm/cglm.h>
#include <cglm/struct.h>

#include "types.h"
typedef u32 shader_t;

shader_t shader_new(const char* vertexSource, const char* fragmentSource);
void shader_set_projection(shader_t shader, vec2s size, vec2s zBounds) ;
void shader_use(shader_t shader);
void shader_set_mat4f(shader_t shader, mat4 data, const char* name);
void shader_set_vec3f(shader_t shader, vec3s data, const char* name);
#endif // SHADER_H
