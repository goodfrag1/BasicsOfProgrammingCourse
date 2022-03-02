#include "deleteWordsEqualLast.h"

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend) + 1;

    return true;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != w1.end - 1 && w2.begin != w2.end - 1 && (*w1.begin == *w2.begin))
        w1.begin++, w2.begin++;

    return *w1.begin - *w2.begin;
}

void deleteWordsEqualLast(char *s) {
    WordDescriptor lastWord;

    if (getWordReverse(getEndOfString(s), s - 1, &lastWord)) {
        char *readPtr = s;
        char *recPtr = s;
        WordDescriptor currentWord;
        while (getWord(readPtr, &currentWord)) {
            if (areWordsEqual(currentWord, lastWord) != 0) {
                recPtr = copy(currentWord.begin, currentWord.end, recPtr);
                *recPtr++ = ' ';
            }
            readPtr = currentWord.end;
        }
        if (recPtr != s)
            recPtr--;

        *recPtr = '\0';
    } else
        return;
}

void test_deleteWordsEqualLast_notOneWord() {
    char s[] = "100 101 100 101 101";
    deleteWordsEqualLast(s);
    ASSERT_STRING("100 100", s);
}

void test_deleteWordsEqualLast_oneWord() {
    char s[] = "100";
    deleteWordsEqualLast(s);
    ASSERT_STRING("", s);
}

void test_deleteWordsEqualLast_equalWords() {
    char s[] = "100 100 100 100";
    deleteWordsEqualLast(s);
    ASSERT_STRING("", s);
}

void deleteWordsEqualLast_emptyString() {
    char s[] = " ";
    deleteWordsEqualLast(s);
    ASSERT_STRING("", s);
}

void test_17Task() {
    test_deleteWordsEqualLast_equalWords();
    test_deleteWordsEqualLast_notOneWord();
    test_deleteWordsEqualLast_oneWord();
}