#include "countWordsPalindromes.h"

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int countWordsPalindromes(char *s) {
    WordDescriptor word;
    int count = 0;
    while (*s != '\0') {
        if (getWord(s, &word)) {
            s = word.end;
            while (word.begin < word.end) {
                if (*word.begin != *(word.end - 1))
                    count--;
                word.begin++;
                word.end--;
            }
            count++;
        } else
            return 0;
    }

    return count;
}

void test_countWordsPalindromes_notEmptyString() {
    char s[] = "gag aga bad";
    printf("%d\n", countWordsPalindromes(s) == 2);
}

void test_countWordsPalindromes_emptyString() {
    char s[] = " ";
    printf("%d\n", countWordsPalindromes(s) == 0);
}

void test_8Task() {
    test_countWordsPalindromes_emptyString();
    test_countWordsPalindromes_notEmptyString();
}

