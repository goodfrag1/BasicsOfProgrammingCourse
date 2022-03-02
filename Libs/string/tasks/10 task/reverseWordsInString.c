#include "reverseWordsInString.h"

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findSpaceReverse(rbegin, rend);
    if (word->begin == rend)
        return 0;

    word->end = findSpaceReverse(rbegin,rend);

    return 1;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void reverseWordsInString(char *s) {
    char *endOfString = getEndOfString(s);
    char *endOfStringBuffer = copy(s, endOfString, stringBuffer);
    WordDescriptor word;
    while (*s != '\0') {
        getWordReverse(endOfStringBuffer, stringBuffer, &word);
        copy(word.begin, word.end, s);
        endOfStringBuffer=word.begin;
    }
}

void test_reverseWordsInString() {
    char s[] = "Hello world";
    reverseWordsInString(s);

    ASSERT_STRING("world Hello", s);
}

void test_10Task() {
    test_reverseWordsInString();
}