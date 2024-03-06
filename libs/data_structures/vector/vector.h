#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t initialCapacity);
void reserve(vector *v, size_t newCapacity);

#endif
