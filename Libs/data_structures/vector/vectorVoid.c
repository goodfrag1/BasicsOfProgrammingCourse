#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    if (malloc(n)) {
        v.size = 0;
        v.capacity = n;
        v.data = malloc(baseTypeSize * n);

        return v;
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->capacity = 0;
        v->size = 0;
        v->data = NULL;
    } else if (realloc(v->data, v->baseTypeSize * newCapacity) == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    } else {
        v->capacity = newCapacity;
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    }
}

void shrinkToFitV(vectorVoid *v){
    v->capacity = v->size;
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v->data);
}