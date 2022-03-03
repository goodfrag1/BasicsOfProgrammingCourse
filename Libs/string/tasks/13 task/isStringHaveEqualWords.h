#ifndef LABA_5B_ISSTRINGHAVEEQUALWORDS_H
#define LABA_5B_ISSTRINGHAVEEQUALWORDS_H

#include "../../string_.h"
#include "stdio.h"

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

bool isStringHaveEqualWords(char *s);

void test_13Task();

#endif //LABA_5B_ISSTRINGHAVEEQUALWORDS_H
