#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

position getLeftMin(matrix m) {
    return getMinValuePos(m);
}

void swapPenultimateRow(matrix m) {
    position minElementPos = getLeftMin(m);
    int minElementCol = minElementPos.colIndex;
    for (int i = m.nRows - 1; i >= 0; --i)
        m.values[m.nRows - 2][i] = m.values[i][minElementCol];
}

void test_swapPenultimateRow_oneElement() {
    matrix m1 = createMatrixFromArray((int[]) {1}, 1, 1);
    matrix m2 = createMatrixFromArray((int[]) {1}, 1, 1);

    assert(twoMatricesEqual(m1, m2));
}

void test_swapPenultimateRow_notOneElement() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 3, 2, 4}, 2, 2);

    assert(twoMatricesEqual(m1, m2));
}

void test() {
    test_swapPenultimateRow_notOneElement();
    test_swapPenultimateRow_oneElement();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    swapPenultimateRow(m);

    outputMatrix(m);

    return 0;
}
