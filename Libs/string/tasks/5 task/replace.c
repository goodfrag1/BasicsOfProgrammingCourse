#include "replace.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

//char *findWordInString(char *s, char *w) {
//    while (*s != '\0')
//        if (*s == *w) {
//            bool isFound = true;
//            char *wordSearchStart = w;
//            char *sSearchStart = s;
//            while (*wordSearchStart && isFound)
//                isFound = *wordSearchStart++ == *sSearchStart;
//            if (isFound)
//                return s;
//        }
//    s++;
//
//    return s;
//}

//void replace(char *source, char *w1, char *w2) {
//    size_t w1Size = strlen_(w1);
//    size_t w2Size = strlen_(w2);
//    WordDescriptor word1 = {w1, w1 + w1Size};
//    WordDescriptor word2 = {w2, w2 + w2Size};
//
//    char *readPtr, *recPtr;
//    if (w1Size >= w2Size) {
//        readPtr = source;
//        recPtr = source;
//    } else {
//        char *endOfStringBuffer = copy(source, getEndOfString(source), stringBuffer);
//        *endOfStringBuffer = '\0';
//        readPtr = stringBuffer;
//        recPtr = source;
//    }
//    while (*readPtr != '\0') {
//        char *beginWord = findWordInString(readPtr, word1.begin);
//        recPtr = copy(readPtr, beginWord, recPtr);
//        readPtr = beginWord + w1Size;
//
//        if (*beginWord == '\0') {
//            *recPtr = '\0';
//            return;
//        }
//        memcpy(recPtr, word2.begin, w2Size);
//        recPtr += w2Size;
//    }
//    *recPtr = '\0';
//}

void test_replace_oneWord() {
    char s[] = "Hello";
    replace(s, "Hello", "Hi");
    assertString("Hi", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_5Task() {
    test_replace_oneWord();
}