#include <stdio.h>
#include "vector.h"
#include "vectorVoid.h"

void test() {
    test_createVector_notZeroCapacity();
    test_createVector_zeroCapacity();
    test_clear_notEmptyVector();
    test_shrinkToFit_fullVector();
    test_shrinkToFit_emptyVector();
    test_isEmpty_fullVector();
    test_isEmpty_emptyVector();
    test_isFull_fullVector();
    test_isFull_emptyVector();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();

}

int main() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        printf("%f ", x);
    }

    return 0;
}


