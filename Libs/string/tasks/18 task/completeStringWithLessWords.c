#include "completeStringWithLessWords.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend) + 1;

    return true;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void completeStringWithLessWords(char *s1, char *s2, int n1, int n2) {
    if (n1 == n2) {
        return;
    } else if (n2 > n1)
        swap(&n1, &n2);

    int diff = n1 - n2;
    char *readPtr = getEndOfString(s1) - 1;
    WordDescriptor word;
    while (diff != 0) {
        getWordReverse(readPtr, s1 - 1, &word);
        readPtr -= word.end - word.begin + 1;
        readPtr = findNonSpaceReverse(readPtr, s1 - 1);
        diff--;
    }
    char *endOfSecondString = getEndOfString(s2);
    *endOfSecondString++ = ' ';
    *copy(word.begin, getEndOfString(s1), endOfSecondString) = '\0';
}


void test_completeStringWithLessWords_moreWordsInFirstString() {
    char s1[] = "Hello world";
    char s2[] = "BYE";
    completeStringWithLessWords(s1, s2, 2, 1);

    ASSERT_STRING("BYE world", s2);
}

void test_completeStringWithLessWords_moreWordsInSecondString() {
    char s1[] = "world";
    char s2[] = "BYE perfect";
    completeStringWithLessWords(s1, s2, 1, 2);

    ASSERT_STRING("BYE perfect world", s2);
}

void test_completeStringWithLessWords_equalCountOfWordsInStrings() {
    char s1[] = "BYE my";
    char s2[] = "perfect world";
    completeStringWithLessWords(s1, s2, 2, 2);

    ASSERT_STRING("perfect world", s2);
}

void test_completeStringWithLessWords_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    completeStringWithLessWords(s1, s2, 1, 1);

    ASSERT_STRING("", s2);
}

void test_18Task() {
    test_completeStringWithLessWords_moreWordsInFirstString();
    test_completeStringWithLessWords_moreWordsInSecondString();
    test_completeStringWithLessWords_equalCountOfWordsInStrings();
    test_completeStringWithLessWords_emptyStrings();
}