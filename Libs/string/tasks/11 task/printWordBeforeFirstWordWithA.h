#ifndef LABA_5B_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define LABA_5B_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../../string_.h"
#include "stdio.h"
#include "assert.h"

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore);


void printWordBeforeFirstWordWithA(char *s);

void testAll_getWordBeforeFirstWordWithA();

#endif //LABA_5B_PRINTWORDBEFOREFIRSTWORDWITHA_H
