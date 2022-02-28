#ifndef LABA_5E_DIGITTOSTART_H
#define LABA_5E_DIGITTOSTART_H

#include "../../string_.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

void digitToStart(WordDescriptor word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

void test_3Task();

#endif //LABA_5E_DIGITTOSTART_H
