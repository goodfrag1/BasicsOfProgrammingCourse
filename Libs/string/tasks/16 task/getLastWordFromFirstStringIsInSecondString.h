#ifndef LABA_5B_GETLASTWORDFROMFIRSTSTRINGISINSECONDSTRING_H
#define LABA_5B_GETLASTWORDFROMFIRSTSTRINGISINSECONDSTRING_H

#include "../../string_.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

WordDescriptor getLastWordFromFirstStringIsInSecondString(char *s1, char *s2);

void test_16Task();

#endif //LABA_5B_GETLASTWORDFROMFIRSTSTRINGISINSECONDSTRING_H
