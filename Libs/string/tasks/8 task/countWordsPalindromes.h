#ifndef LABA_5B_COUNTWORDSPALINDROMES_H
#define LABA_5B_COUNTWORDSPALINDROMES_H

#include "../../string_.h"
#include "stdio.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

int countWordsPalindromes(char *s);

void test_8Task();

#endif //LABA_5B_COUNTWORDSPALINDROMES_H
