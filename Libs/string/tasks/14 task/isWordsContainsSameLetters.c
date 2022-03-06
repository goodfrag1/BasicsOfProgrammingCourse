#include "isWordsContainsSameLetters.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *readPtr = s;
    bag->size = 0;
    while (getWord(readPtr, &bag->words[bag->size])) {
        readPtr = bag->words[bag->size].end;
        bag->size++;
    }
    for (int i = 0; i < bag->size; i++)
        *bag->words[i].end = '\0';
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

int cmp(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;


    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != w1.end - 1 && w2.begin != w2.end - 1 && (*w1.begin == *w2.begin))
        w1.begin++, w2.begin++;

    return *w1.begin - *w2.begin;
}


bool isStringHaveEqualWords() {
    for (int i = 0; i < _bag.size; ++i)
        for (int j = i + 1; j <= _bag.size - 1; ++j)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

bool isWordsContainsSameLetters(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    for (int i = 0; i < _bag.size; ++i)
        qsort(_bag.words[i].begin, _bag.words[i].end -
        _bag.words[i].begin, sizeof(char), cmp);

    return isStringHaveEqualWords(stringBuffer);
}

void test_isWordsContainsSameLetters_true() {
    char s[] = "qwerty wertyq";
    printf("%d\n", isWordsContainsSameLetters(s));
}

void test_isWordsContainsSameLetters_false() {
    char s[] = "qwerty wertyeq";
    printf("%d\n", !isWordsContainsSameLetters(s));
}

void test_isWordsContainsSameLetters_emptyString() {
    char s[] = "";
    printf("%d\n", !isWordsContainsSameLetters(s));
}

void test_14Task() {
    test_isWordsContainsSameLetters_true();
    test_isWordsContainsSameLetters_false();
    test_isWordsContainsSameLetters_emptyString();
}