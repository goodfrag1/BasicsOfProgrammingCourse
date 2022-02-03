#include "vector.h"

vector createVector(size_t n) {
    vector v;
    if (malloc(n)) {
        v.size = 0;
        v.capacity = n;
        v.data = malloc(sizeof(v.data) * n);

        return v;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->capacity = 0;
        v->size = 0;
        v->data = NULL;
    } else if (realloc(v->data, sizeof(v->data) * newCapacity) == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
        v->data = realloc(v->data, sizeof(v->data) * newCapacity);
    } else {
        v->capacity = newCapacity;
        v->data = realloc(v->data, sizeof(v->data) * newCapacity);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
}