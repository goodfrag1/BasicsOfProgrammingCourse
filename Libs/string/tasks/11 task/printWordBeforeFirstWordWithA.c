#include "printWordBeforeFirstWordWithA.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    WordDescriptor word1;
    char *begin = s;
    if (!getWord(begin, &word1))
        return EMPTY_STRING;
    else if (find(word1.begin, word1.end, 'a') != word1.end || find(word1.begin, word1.end, 'A') != word1.end)
        return FIRST_WORD_WITH_A;

    begin = word1.end;
    WordDescriptor word2;
    while (getWord(begin, &word2)) {
        if (find(word2.begin, word2.end, 'a') != word2.end || find(word2.begin, word2.end, 'A') != word2.end) {
            *beginWordBefore = word1.begin;
            *endWordBefore = word1.end;

            return WORD_FOUND;
        }
        word1 = word2;
        begin = word2.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *beginWordBefore;
    char *endWordBefore;

    if (getWordBeforeFirstWordWithA(s, &beginWordBefore, &endWordBefore) == WORD_FOUND) {
        *endWordBefore = '\0';

        printf("%s\n", beginWordBefore);
    }
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "bc a";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == WORD_FOUND);
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("bc", got);

    char s5[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s5, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}