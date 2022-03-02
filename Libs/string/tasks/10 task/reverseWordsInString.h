#ifndef LABA_5B_REVERSEWORDSINSTRING_H
#define LABA_5B_REVERSEWORDSINSTRING_H

#include "../../string_.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

void reverseWordsInString(char *s);

void test_10Task();

#endif //LABA_5B_REVERSEWORDSINSTRING_H
