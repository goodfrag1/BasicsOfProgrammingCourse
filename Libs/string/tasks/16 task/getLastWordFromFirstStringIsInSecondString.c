#include "getLastWordFromFirstStringIsInSecondString.h"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    return strcmp_(w1.begin, w2.begin);
}

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

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}

WordDescriptor getLastWordFromFirstStringIsInSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    WordDescriptor lastWord = {NULL, NULL};
    bool isLast = false;
    for (int i = _bag.size - 1; i >= 0 && !isLast; --i)
        for (int j = 0; j < _bag2.size && !isLast; ++j)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                lastWord = _bag.words[i];
                isLast = true;
            }

    return lastWord;
}

void test_getLastWordFromFirstStringIsInSecondString_wordInString() {
    char s1[] = "help me end this lab";
    char s2[] = "this is end";
    WordDescriptor resWord = getLastWordFromFirstStringIsInSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(resWord, res);

    ASSERT_STRING("this", res);
}

void test_getLastWordFromFirstStringIsInSecondString_noEqualWords() {
    char s1[] = "help me end this lab";
    char s2[] = "just getting started";
    WordDescriptor resWord = getLastWordFromFirstStringIsInSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(resWord, res);

    ASSERT_STRING("", res);
}

void test_getLastWordFromFirstStringIsInSecondString_emptyFirstString() {
    char s1[] = "";
    char s2[] = "just getting started";
    WordDescriptor resWord = getLastWordFromFirstStringIsInSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(resWord, res);

    ASSERT_STRING("", res);
}

void test_getLastWordFromFirstStringIsInSecondString_emptySecondString() {
    char s1[] = "help me end this lab";
    char s2[] = "";
    WordDescriptor resWord = getLastWordFromFirstStringIsInSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(resWord, res);

    ASSERT_STRING("", res);
}

void test_16Task() {
    test_getLastWordFromFirstStringIsInSecondString_wordInString();
    test_getLastWordFromFirstStringIsInSecondString_noEqualWords();
    test_getLastWordFromFirstStringIsInSecondString_emptyFirstString();
    test_getLastWordFromFirstStringIsInSecondString_emptySecondString();
}