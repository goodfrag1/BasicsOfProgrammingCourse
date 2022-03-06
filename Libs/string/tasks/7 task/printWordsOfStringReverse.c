#include "printWordsOfStringReverse.h"

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

void printWordsOfStringReverse(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = _bag.size; i >= 0; --i)
        printf("%s\n", _bag.words[i].begin);
}