#include <stdio.h>
#include "Libs/algorithms/functions/function.h"
#include "Libs/data_structures/vector/vector.h"

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    vector v = createVector(4);
    reserve(&v, 4);
    test();

    return 0;
}
