#include <stdio.h>
#include "Libs/algorithms/functions/function.h"
#include "Libs/data_structures/vector/vector.h"

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    vector v = createVector(4);
    reserve(&v, 4);
    test();

    return 0;
}
