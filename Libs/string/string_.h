#ifndef LABA_5E_STRING__H
#define LABA_5E_STRING__H

#define ASSERT_STRING (expected ,got) assertString(expected ,got, __FILE__ , __FUNCTION__ , __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include "string.h"
#include "stdbool.h"

char stringBuffer[MAX_STRING_SIZE + 1];

void assertString(char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

size_t strlen_(const char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(char *lhs, char *rhs);

char *copy(char *beginSource, char *endSource,
           char *beginDestination);

char *copyIf(char *beginSource, char *endSource,
             char *beginDestination, int (*f)(char));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(char));


#endif //LABA_5E_STRING__H
