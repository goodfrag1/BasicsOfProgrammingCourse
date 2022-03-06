#include "isEveryLetterInString.h"

bool isEveryLetterInString(char *s, char *word) {
    bool letters[MAX_STRING_SIZE];
    for (int i = 0; i < MAX_STRING_SIZE; ++i)
        letters[i] = false;

    while (*s != '\0') {
        if (isalpha(*s) && !letters[*s])
            letters[*s] = true;
        s++;
    }

    while (*word != '\0') {
        if (!letters[*word])
            return false;
        word++;
    }

    return true;
}

void test_isEveryLetterInString_true() {
    char s[] = "Hello";
    char word[] = "Hell";

    printf("%d\n", isEveryLetterInString(s, word));
}

void test_isEveryLetterInString_false() {
    char s[] = "Hello";
    char word[] = "Hi";

    printf("%d\n", !isEveryLetterInString(s, word));
}

void test_isEveryLetterInString_notOneWordInString() {
    char s[] = "Hello world";
    char word[] = "wrld";

    printf("%d\n", isEveryLetterInString(s, word));
}

void test_isEveryLetterInString_emptyString() {
    char s[] = "";
    char word[] = "Hi";

    printf("%d\n", !isEveryLetterInString(s, word));
}

void test_isEveryLetterInString_emptyWord() {
    char s[] = "Hello";
    char word[] = "";

    printf("%d\n", isEveryLetterInString(s, word));
}

void test_19Task() {
    test_isEveryLetterInString_true();
    test_isEveryLetterInString_false();
    test_isEveryLetterInString_notOneWordInString();
    test_isEveryLetterInString_emptyString();
    test_isEveryLetterInString_emptyWord();
}