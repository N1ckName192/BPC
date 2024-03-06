#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

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

    if (newCapacity == v->capacity) {
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
    if (v->data == NULL) {
        return;
    }

    v->size = 0;
    free(v->data);
    v->data = NULL;
}

void shrinkToFit(vector *v) {
    if (v->size == 0) {
        return;
    }

    v->data = v->size > 0 ? (int *)realloc(v->data, v->size * sizeof(int)) : NULL;
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    if (v->data == NULL) {
        return;
    }

    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void pushBack(vector *v, int x) {
    if (v->size == v->capacity) {
        reserve(v, v->capacity * 2);
    }

    v->data[v->size++] = x;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    assert(v.capacity == 1);
    free(v.data);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 20);
    assert(v.size == 2);
    assert(v.capacity == 2);
    free(v.data);
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Error: popBack()\n");
        exit(1);
    }
    v->size--;
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    free(v.data);
}


