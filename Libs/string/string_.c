#include "string_.h"
#include "memory.h"
#include "stdio.h"

void assertString(char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && *begin == ' ')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && *begin != ' ')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && *rbegin == ' ')
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && *rbegin != ' ')
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    if (strlen_(lhs) == strlen_(rhs))
        return 0;

    return strlen_(lhs) - strlen_(rhs);
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    while (beginSource != endSource) {
        memcpy(beginDestination, beginSource, sizeof(char));
        beginDestination++;
        beginSource++;
    }

    return beginDestination;
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(char)) {
    while (beginSource != endSource)
        if (f(*beginSource)) {
            memcpy(beginDestination, beginSource, sizeof(char));
            beginDestination++;
            beginSource++;
        } else
            beginSource++;

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource)
        if (f) {
            memcpy(beginDestination, rbeginSource, sizeof(char));
            beginDestination++;
            rbeginSource--;
        } else
            rbeginSource--;

    return ++beginDestination;
}