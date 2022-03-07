#ifndef LABA_5B_COMPLETESTRINGWITHLESSWORDS_H
#define LABA_5B_COMPLETESTRINGWITHLESSWORDS_H

#include "../../string_.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

void completeStringWithLessWords(char *s1, char *s2, int n1, int n2);

void test_18Task();

#endif //LABA_5B_COMPLETESTRINGWITHLESSWORDS_H
