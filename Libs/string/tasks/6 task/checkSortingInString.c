#include "checkSortingInString.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    return strcmp_(w1.begin, w2.begin);
}

bool checkSortingInString(char *s) {
    WordDescriptor currentWord;
    WordDescriptor previousWord;
    if (getWord(s, &previousWord)) {
        getWord(s, &previousWord);
        s = previousWord.end;
        getWord(s, &currentWord);

        while (*s != '\0' && areWordsEqual(previousWord, currentWord) <= 0) {
            getWord(s, &currentWord);
            if (areWordsEqual(previousWord, currentWord) <= 0)
                return true;
            else {
                previousWord = currentWord;
                s = previousWord.end;
            }
        }
    } else
        return false;

    return false;
}

void test_checkSortingInString_notOneWordTrue() {
    char s1[] = "BA BB";

    printf("%d\n", checkSortingInString(s1));
}

void test_checkSortingInString_notOneWordFalse() {
    char s1[] = "BB BA";

    printf("%d\n", !checkSortingInString(s1));
}

void test_checkSortingInString_oneWord() {
    char s1[] = "BA";

    printf("%d", !checkSortingInString(s1));
}

void test_6Task() {
    test_checkSortingInString_notOneWordFalse();
    test_checkSortingInString_notOneWordTrue();
    test_checkSortingInString_oneWord();
}
