#include "removeExtraSpaces.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

int isGraph(char s) {
    return s != ' ';
}

void removeExtraSpaces(char *s) {
    char *endSource = getEndOfString(s);
    char *beginSource = findSpace(s);
    char *destination = copyIf(beginSource, endSource, beginSource + 1, isGraph);
    *destination = '\0';
}

void test_removeExtraSpaces_notZeroSpaces() {
    char s[] = "Nice lab, IS";
    removeExtraSpaces(s);
    assertString("Nice lab,IS", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_removeExtraSpaces_zeroSpaces() {
    char s[] = "Badlab,IS";
    removeExtraSpaces(s);
    assertString("Badlab,IS", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_2Task() {
    test_removeExtraSpaces_notZeroSpaces();
    test_removeExtraSpaces_zeroSpaces();
}