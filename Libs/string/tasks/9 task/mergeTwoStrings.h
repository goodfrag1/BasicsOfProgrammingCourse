#ifndef LABA_5B_MERGETWOSTRINGS_H
#define LABA_5B_MERGETWOSTRINGS_H

#include "../../string_.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

void mergeTwoStrings(char *s, char *str1, char *str2);

void test_9Task();

#endif //LABA_5B_MERGETWOSTRINGS_H
