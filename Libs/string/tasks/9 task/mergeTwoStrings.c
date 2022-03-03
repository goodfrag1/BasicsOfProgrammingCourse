#include "mergeTwoStrings.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void mergeTwoStrings(char *s, char *str1, char *str2) {
    char *recPtr = s;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = str1, *beginSearch2 = str2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            recPtr = copy(word1.begin, word1.end, recPtr);
            *recPtr++ = ' ';
            beginSearch1 = word1.end;
        } else if (isW2Found) {
            recPtr = copy(word2.begin, word2.end, recPtr);
            *recPtr++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (recPtr != s)
        recPtr--;

    *recPtr = '\0';
}

void test_mergeTwoStrings_equalCountOfWords() {
    char s[MAX_STRING_SIZE];
    mergeTwoStrings(s, "Laba very", "good ,IS");
    ASSERT_STRING("Laba very good ,IS", s);
}

void test_mergeTwoStrings_moreWordsInFirstString() {
    char s[MAX_STRING_SIZE];
    mergeTwoStrings(s, "I love", "programming");
    ASSERT_STRING("I love programming", s);
}

void test_mergeTwoStrings_moreWordsInSecondString() {
    char s[MAX_STRING_SIZE];
    mergeTwoStrings(s, "I ", "hate programming");
    ASSERT_STRING("I hate programming", s);
}

void test_mergeTwoStrings_emptyStrings() {
    char s[MAX_STRING_SIZE];
    mergeTwoStrings(s, " ", " ");
    ASSERT_STRING("", s);
}

void test_9Task() {
    test_mergeTwoStrings_equalCountOfWords();
    test_mergeTwoStrings_moreWordsInFirstString();
    test_mergeTwoStrings_moreWordsInSecondString();
    test_mergeTwoStrings_emptyStrings();
}