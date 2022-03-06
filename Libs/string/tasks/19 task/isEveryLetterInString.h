#ifndef LABA_5B_ISEVERYLETTERINSTRING_H
#define LABA_5B_ISEVERYLETTERINSTRING_H

#include "../../string_.h"
#include "stdio.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

void test_19Task();

bool isEveryLetterInString(char *s, char *word);

#endif //LABA_5B_ISEVERYLETTERINSTRING_H
