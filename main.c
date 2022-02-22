#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

bool checkIsSpecialElement(matrix m, size_t k) {
    int max = m.values[0][k];
    int sum = 0;
    for (int i = 0; i < m.nRows; ++i) {
        sum += m.values[i][k];
        if (m.values[i][k] > max)
            max = m.values[i][k];
    }

    return sum - max < max;
}

int getNSpecialElement(matrix m) {
    int count = 0;
    for (size_t i = 0; i < m.nCols; ++i)
        count += checkIsSpecialElement(m, i);

    return count;
}

void test_getNSpecialElement_notEqualElements() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4, 2, 3, 6, 7, 12, 2, 1, 2}, 3, 4);


    assert(getNSpecialElement(m) == 2);
}

void test_getNSpecialElement_equalElements() {
    matrix m = createMatrixFromArray((int[]) {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, 3, 4);


    assert(getNSpecialElement(m) == 0);
}

void test() {
    test_getNSpecialElement_equalElements();
    test_getNSpecialElement_notEqualElements();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%d", getNSpecialElement(m));

    return 0;
}
