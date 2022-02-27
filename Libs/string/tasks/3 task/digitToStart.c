#include "digitToStart.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int isDigit(char x) {
    return x >= '0' && x <= '9';
}

int isAlpha(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      stringBuffer - 1, word.begin, isDigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isAlpha);
}

void digitToStart_additionalTask(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf(stringBuffer,
                               endStringBuffer, word.begin, isDigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isAlpha);
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpaceReverse(word->begin, rend);

    return 1;
}

void test_getWordReverse() {
    char s[] = "Hello";
    char *endOfString = getEndOfString(s);
    WordDescriptor word;
    getWordReverse(endOfString - 1, s, &word);

    assertString("Hello", word.end, __FILE__, __FUNCTION__, __LINE__);
}


void test_digitToStart_notZeroDigitsInString() {
    char s[] = "A32BC1";
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        getWord(beginSearch, &word);
        digitToStart(word);
        beginSearch = word.end;
    }

    assertString("123ABC", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_digitToStart_additionalTask_notZeroDigitsInString() {
    char s[] = "Hi123";
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        getWord(beginSearch, &word);
        digitToStart_additionalTask(word);
        beginSearch = word.end;
    }

    assertString("123Hi", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_digitToStart_additionalTask_zeroDigitsInString() {
    char s[] = "Hello";
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        getWord(s, &word);
        digitToStart_additionalTask(word);
        beginSearch = word.end;
    }

    assertString("Hello", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_digitToStart_additionalTask_emptyString() {
    char s[] = " ";
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        getWord(s, &word);
        digitToStart_additionalTask(word);
        beginSearch = word.end;
    }

    assertString(" ", s, __FILE__, __FUNCTION__, __LINE__);
}


void test() {
    test_getWordReverse();
    test_digitToStart_notZeroDigitsInString();
    test_digitToStart_additionalTask_notZeroDigitsInString();
    test_digitToStart_additionalTask_zeroDigitsInString();
    test_digitToStart_additionalTask_emptyString();
}
