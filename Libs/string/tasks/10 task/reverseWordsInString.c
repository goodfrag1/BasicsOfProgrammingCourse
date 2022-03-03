#include "reverseWordsInString.h"

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end - 1, rend) + 1;

    return true;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void reverseWordsInString(char *s) {
    char *endOfStringBuffer = copy(s, getEndOfString(s), stringBuffer);
    char *recPtr = s;
    char *readPtr = endOfStringBuffer - 1;
    WordDescriptor word;

    while (getWordReverse(readPtr, stringBuffer - 1, &word)) {
        recPtr = copy(word.begin, word.end, recPtr);
        *recPtr++ = ' ';
        readPtr -= word.end - word.begin + 1;
        readPtr = findNonSpaceReverse(readPtr, stringBuffer - 1);
    }

    if (recPtr != s)
        recPtr--;

    *recPtr = '\0';
}

void test_reverseWordsInString_notOneWord() {
    char s[] = "Hello world";
    reverseWordsInString(s);

    ASSERT_STRING("world Hello", s);
}

void test_reverseWordsInString_oneWord() {
    char s[] = "Hello";
    reverseWordsInString(s);

    ASSERT_STRING("Hello", s);
}

void test_reverseWordsInString_emptyString() {
    char s[] = "";
    reverseWordsInString(s);

    ASSERT_STRING("", s);
}

void test_10Task() {
    test_reverseWordsInString_notOneWord();
    test_reverseWordsInString_oneWord();
    test_reverseWordsInString_emptyString();
}