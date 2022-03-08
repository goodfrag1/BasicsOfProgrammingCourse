#include "replace.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

char *findWordInString(char *s, char *w) {
    s = findNonSpace(s);
    char *readPtr = w;
    while (*s != '\0' && *readPtr != '\0') {
        if (*s == *readPtr) {
            s++;
            readPtr++;
        } else {
            readPtr = w;
            s = findSpace(s);
            s = findNonSpace(s);
        }
    }

    if (*readPtr == '\0')
        return s - strlen_(w);
    else
        return s;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

    char *newReadPtr = findWordInString(readPtr, w1);
    recPtr += newReadPtr - readPtr;
    readPtr = newReadPtr;
    while (*readPtr != '\0') {
        readPtr += strlen_(w1);
        recPtr = copy(word2.begin, word2.end, recPtr);
        newReadPtr = findWordInString(readPtr, w1);
        if (*newReadPtr == '\0')
            recPtr = copy(readPtr, getEndOfString(readPtr), recPtr);
        else
            recPtr = copy(readPtr, newReadPtr, recPtr);
        readPtr = newReadPtr;
    }
    *recPtr = '\0';
}

void test_replace_oneWord() {
    char s[] = "Hello";
    replace(s, "Hello", "Hi");
    ASSERT_STRING("Hi", s);
}

void test_replace_notOneWord() {
    char s[] = "Hi Hi Hi Hi";
    replace(s, "Hi", "Hello");
    ASSERT_STRING("Hello Hello Hello Hello", s);
}

void test_5Task() {
    test_replace_oneWord();
    test_replace_notOneWord();
}