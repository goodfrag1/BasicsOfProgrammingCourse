#include "isStringHaveEqualWords.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    for (int i = 0; *s != '\0'; ++i) {
        getWord(s, &bag->words[i]);
        bag->size++;
        s = bag->words[i].end;
    }
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != w1.end - 1 && w2.begin != w2.end - 1 && (*w1.begin == *w2.begin))
        w1.begin++, w2.begin++;

    return *w1.begin - *w2.begin;
}


bool isStringHaveEqualWords(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = 0; i < _bag.size; ++i)
        for (int j = i + 1; j < _bag.size - 1; ++j)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

void test_isStringHaveEqualWords_notOneWord() {
    char s[] = "hi hello hi bye";

    if (isStringHaveEqualWords(s))
        printf("OK\n");
}

void test_isStringHaveEqualWords_oneWord() {
    char s[] = "hi";

    if (isStringHaveEqualWords(s))
        printf("OK\n");
}

void test_isStringHaveEqualWords_emptyString() {
    char s[] = "";

    if (isStringHaveEqualWords(s))
        printf("OK\n");
}

void test_13Task() {
    test_isStringHaveEqualWords_notOneWord();
    test_isStringHaveEqualWords_oneWord();
    test_isStringHaveEqualWords_emptyString();
}