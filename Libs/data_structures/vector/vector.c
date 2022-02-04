#include "vector.h"

vector createVector(size_t n) {
    vector v;
    if (malloc(n)) {
        v.size = 0;
        v.capacity = n;
        v.data = (int *) malloc(sizeof(v.data) * n);

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
        v->data = (int *) realloc(v->data, sizeof(v->data) * newCapacity);
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        v->capacity++;
    else if (v->size == v->capacity)
        reserve(v, v->capacity * 2);
    v->data[v->size] = x;
    v->size++;
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);

    assert(v.size == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    v.size = 2;
    v.data[0] = 1;
    v.data[1] = 2;
    pushBack(&v, 3);

    assert(v.capacity == 4);
    assert(v.size == 3);
    deleteVector(&v);
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    } else
        v->size--;
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
    deleteVector(&v);
}

int *atVector(vector *v, size_t index) {
    if (index <= v->size)
        return &v->data[index];
    else {
        fprintf(stderr, "\"IndexError: a[%ud] is not exists\"", index);
        exit(1);
    }
}

void test_atVector_notEmptyVector() {
    vector v = createVector(2);
    v.data[0] = 1;
    v.size++;

    assert(atVector(&v, 0) == &v.data[0]);
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(2);
    v.data[0] = 1;
    v.data[1] = 2;
    v.size = 2;

    assert(atVector(&v, 1) == &v.data[1]);
    deleteVector(&v);
}

int *back(vector *v) {
    return &v->data[v->size - 1];
}

void test_back_oneElementInVector() {
    vector v = createVector(2);
    v.data[0] = 1;
    v.size++;

    assert(back(&v) == &v.data[0]);
    deleteVector(&v);
}

int *front(vector *v) {
    return &v->data[0];
}

void test_front_oneElementInVector() {
    vector v = createVector(2);
    v.data[0] = 1;
    v.size++;

    assert(front(&v) == &v.data[0]);
    deleteVector(&v);
}
