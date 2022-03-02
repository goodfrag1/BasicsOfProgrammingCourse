#ifndef LABA_5B_DELETEWORDSEQUALLAST_H
#define LABA_5B_DELETEWORDSEQUALLAST_H

#include "../../string_.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

void deleteWordsEqualLast(char *s);

void test_17Task();

#endif //LABA_5B_DELETEWORDSEQUALLAST_H
