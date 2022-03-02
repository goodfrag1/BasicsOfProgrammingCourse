#include "changeDigitsOnSpacesByValue.h"

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}


void changeDigitsOnSpacesByValue(char *s) {
    char *endOfString = getEndOfString(s);
    char *beginOfStringBuffer = stringBuffer;
    char *endOfStringBuffer = copy(s, endOfString, stringBuffer);
    *endOfStringBuffer = '\0';

    while (*beginOfStringBuffer != '\0') {
        if (isalpha(*beginOfStringBuffer))
            *s++ = *beginOfStringBuffer;
        else if (isdigit(*beginOfStringBuffer)) {
            unsigned char x = *beginOfStringBuffer - '0';
            while (x--)
                *s++ = ' ';
        }
        beginOfStringBuffer++;
    }
    *s = '\0';
}

void test_changeDigitsOnSpacesByValue_notZeroDigits() {
    char s[] = "A3B0C1";
    changeDigitsOnSpacesByValue(s);

    ASSERT_STRING("A   BC ",s);
}

void test_changeDigitsOnSpacesByValue_zeroDigits() {
    char s[] = "ABC";
    changeDigitsOnSpacesByValue(s);

    ASSERT_STRING("ABC", s);
}

void test_changeDigitsOnSpacesByValue_emptyString() {
    char s[] = " ";
    changeDigitsOnSpacesByValue(s);

    ASSERT_STRING("", s);
}

void test_4Task() {
    test_changeDigitsOnSpacesByValue_notZeroDigits();
    test_changeDigitsOnSpacesByValue_zeroDigits();
    test_changeDigitsOnSpacesByValue_emptyString();
}
