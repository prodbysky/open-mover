#ifndef EBO_H
#define EBO_H

#include "types.h"

typedef u32 ebo_t;

ebo_t ebo_new(const u32* vertices, u32 n);
void ebo_bind(ebo_t ebo);
void ebo_unbind();

#endif // EBO_H

