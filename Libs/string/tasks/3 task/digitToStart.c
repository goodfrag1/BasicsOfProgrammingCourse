#include "digitToStart.h"

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

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      stringBuffer - 1, word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

// преобразовывает строку таким образом, чтобы цифры каждого слова были
// перенесены в начало слова без изменения порядка следования их в слове,
// буквы переносит в конец слова.
void digitToStart_additionalTask(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf(stringBuffer,
                               endStringBuffer, word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findSpaceReverse(rbegin, rend);
    if (word->begin == rend)
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void test_getWordReverse() {
    char s[] = "Hello";
    char *endOfString = getEndOfString(s);
    WordDescriptor word;
    getWordReverse(endOfString - 1, s, &word);

    ASSERT_STRING("Hello", word.begin);
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

    ASSERT_STRING("123ABC", s);
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

    ASSERT_STRING("123Hi", s);
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

    ASSERT_STRING("Hello", s);
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

    ASSERT_STRING(" ", s);
}


void test_3Task() {
    test_getWordReverse();
    test_digitToStart_notZeroDigitsInString();
    test_digitToStart_additionalTask_notZeroDigitsInString();
    test_digitToStart_additionalTask_zeroDigitsInString();
    test_digitToStart_additionalTask_emptyString();
}
