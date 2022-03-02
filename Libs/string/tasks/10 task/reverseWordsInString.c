#include "reverseWordsInString.h"

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findSpaceReverse(rbegin, rend);
    if (word->begin == rend)
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

//void reverseWordsInString(char *s) {
//    char *endOfString = getEndOfString(s);
//    char *endOfStringBuffer = copy(s, endOfString, stringBuffer);
//    for (int i = 0; *s != '\0'; ++i) {
//        copyIfReverse(endOfStringBuffer-1,stringBuffer,s,getWordReverse)
//        bag->size++;
//        s = bag->words[i].end;
//    }
//}