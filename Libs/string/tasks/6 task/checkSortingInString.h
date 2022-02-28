#ifndef LABA_5B_CHECKSORTINGINSTRING_H
#define LABA_5B_CHECKSORTINGINSTRING_H

#include "../../string_.h"
#include "stdio.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

bool checkSortingInString(char *s);

void test_6Task();

#endif //LABA_5B_CHECKSORTINGINSTRING_H
