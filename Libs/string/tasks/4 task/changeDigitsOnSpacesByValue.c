#include "changeDigitsOnSpacesByValue.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

int isDigit(char x) {
    return x >= '0' && x <= '9';
}


void changeDigitsOnSpacesByValue(char *s) {
    char *endOfString = getEndOfString(s);
    char *endOfStringBuffer = copy(s, endOfString, stringBuffer);
    char *readPtr = stringBuffer;
    char *recPtr = s;

    while (s != endOfString) {
        *s = ' ';
        s++;
    }
    *s = ' ';

    while (readPtr != endOfStringBuffer) {
        if (isDigit(*readPtr))
            recPtr += *readPtr;
        *recPtr = *readPtr;
        readPtr++;
    }
    *recPtr = '\0';
}

void test_changeDigitsOnSpacesByValue_notZeroDigits() {
    char s[] = "A3B0C1";
    changeDigitsOnSpacesByValue(s);
    assertString("A   BC ", s, __FILE__, __FUNCTION__, __LINE__);
}

void test_changeDigitsOnSpacesByValue_zeroDigits() {

}

void test_changeDigitsOnSpacesByValue_emptyString() {

}

void test_4Task() {
    test_changeDigitsOnSpacesByValue_notZeroDigits();
}
