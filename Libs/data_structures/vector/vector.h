#ifndef LABA_5B_VECTOR_H
#define LABA_5B_VECTOR_H

#include "stddef.h"
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

void test_createVector_zeroCapacity();

void test_createVector_notZeroCapacity();

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);

void test_clear_notEmptyVector();

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

void test_shrinkToFit_fullVector();

void test_shrinkToFit_emptyVector();

// освобождает память, выделенную вектору
void deleteVector(vector *v);

// проверят пуст ли вектор
bool isEmpty(vector *v);

void test_isEmpty_fullVector();

void test_isEmpty_emptyVector();

// проверят полон ли вектор
bool isFull(vector *v);

void test_isFull_fullVector();

void test_isFull_emptyVector();

// добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

// удаляет последний элемент из вектора
void popBack(vector *v);

void test_popBack_notEmptyVector();

// возвращает указатель на index-ый элемент вектора
int *atVector(vector *v, size_t index);

void test_atVector_notEmptyVector();

void test_atVector_requestToLastElement();

// возвращает указатель на последний элемент вектора.
int *back(vector *v);

void test_back_oneElementInVector();

// возвращает указатель на нулевой элемент вектора.
int *front(vector *v);

void test_front_oneElementInVector();

#endif //LABA_5B_VECTOR_H