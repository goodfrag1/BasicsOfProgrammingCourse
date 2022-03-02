#include "removeNonLetters.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

int isGraph(char s) {
    return s != ' ';
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isGraph);
    *destination = '\0';
}

void test_removeNonLetters_notEmptyString() {
    char s[] = "Hi 123";
    removeNonLetters(s);

    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_emptyString() {
    char s[] = " ";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_1Task() {
    test_removeNonLetters_emptyString();
    test_removeNonLetters_notEmptyString();
}
