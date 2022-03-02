#include "removeExtraSpaces.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void removeExtraSpaces(char *s) {
    char *endSource = getEndOfString(s);
    char *beginSource = findSpace(s);
    char *destination = copyIf(beginSource, endSource, beginSource + 1, isgraph);
    *destination = '\0';
}

void test_removeExtraSpaces_notZeroSpaces() {
    char s[] = "Nice lab, IS";
    removeExtraSpaces(s);

    ASSERT_STRING("Nice lab,IS", s);
}

void test_removeExtraSpaces_zeroSpaces() {
    char s[] = "Badlab,IS";
    removeExtraSpaces(s);

    ASSERT_STRING("Badlab,IS", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[] = " ";
    removeExtraSpaces(s);

    ASSERT_STRING(" ", s);
}

void test_2Task() {
    test_removeExtraSpaces_notZeroSpaces();
    test_removeExtraSpaces_zeroSpaces();
    test_removeExtraSpaces_emptyString();
}