#ifndef TEXTURE_H
#define TEXTURE_H
#include "types.h"

typedef u32 texture_t; 

texture_t texture_new(const char* name);
void texture_bind(texture_t texture);
void texture_unbind();

#endif // TEXTURE_H
