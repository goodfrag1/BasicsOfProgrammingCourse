#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    if (malloc(baseTypeSize * n)) {
        v.size = 0;
        v.capacity = n;
        v.data = malloc(baseTypeSize * n);
        v.baseTypeSize = baseTypeSize;

        return v;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (realloc(v->data, v->baseTypeSize * newCapacity) == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity == 0) {
        v->capacity = newCapacity;
        v->size = 0;
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    } else {
        v->capacity = newCapacity;
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    } else
        v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);
    setVectorValueV(v, v->size, source);
    v->size++;
}