#ifndef LABA_5B_VECTORVOID_H
#define LABA_5B_VECTORVOID_H

#include <limits.h>
#include "stddef.h"
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора

    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                         // например, если вектор хранит int -
                         // то поле baseTypeSize = sizeof(int)
                         // если вектор хранит float -
                         // то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);


#endif //LABA_5B_VECTORVOID_H
