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
    assertString("Hi123", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_removeNonLetters_emptyString() {
    char s[] = " ";
    removeNonLetters(s);
    assertString("", s, __FILE__, __FUNCTION__, __LINE__);
}

void test(){
    test_removeNonLetters_emptyString();
    test_removeNonLetters_notEmptyString();
}
