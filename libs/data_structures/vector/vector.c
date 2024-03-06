#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

vector createVector(size_t initialCapacity) {
    vector v;
    v.data = initialCapacity > 0 ? (int *)malloc(initialCapacity * sizeof(int)) : NULL;
    v.size = 0;
    v.capacity = initialCapacity;
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
        return;
    }

    if (newCapacity < v->size) {
        newCapacity = v->size;
    }

    int *newData = (int *)realloc(v->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        fprintf(stderr, "bad allco.\n");
        exit(EXIT_FAILURE);
    }

    v->data = newData;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
    free(v->data);
    v->data = NULL;
}

void shrinkToFit(vector *v) {
    v->data = v->size > 0 ? (int *)realloc(v->data, v->size * sizeof(int)) : NULL;
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}