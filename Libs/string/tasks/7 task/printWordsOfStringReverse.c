#include "printWordsOfStringReverse.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *endOfString = getEndOfString(s);
    for (int i = 0; s != endOfString; ++i) {
        getWord(s, &bag->words[i]);
        bag->size++;
        s = bag->words[i].end;
    }
    for (int i = 0; i < bag->size; i++)
        *bag->words[i].end = '\0';
}

void printWordsOfStringReverse(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = _bag.size; i > -1; --i)
        printf("%s\n", _bag.words[i].begin);
}