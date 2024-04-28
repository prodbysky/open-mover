#ifndef SHADER_H
#define SHADER_H

#include <cglm/cglm.h>

#include "types.h"
typedef u32 shader_t;

shader_t shader_new(const char* vertexSource, const char* fragmentSource);
void shader_set_mat4f(shader_t shader, mat4 data, const char* name);
#endif // SHADER_H
