#include "replace.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

}

void test_replace_oneWord(){
    char s[]="Hi";
    replace(s,"Hi","Hello");
    assertString("Hello",s,__FILE__,__FUNCTION__,__LINE__);
}

void test_5Task(){
    test_replace_oneWord();
}