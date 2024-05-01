#pragma once
#include "types.h"

typedef u32 texture_t; 

texture_t texture_new(const char* name);
void texture_bind(texture_t texture);
void texture_unbind();

