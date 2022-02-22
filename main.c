#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long scalarProduct = 0;
    for (int k = 0; k < m.nRows; ++k)
        scalarProduct += m.values[i][k] * m.values[k][j];

    return scalarProduct;
}

long long getSpecialScalarProduct(matrix m) {
    int minElementCol = getMinValuePos(m).colIndex;
    int maxElementRow = getMaxValuePos(m).rowIndex;

    return getScalarProductRowAndCol(m, maxElementRow, minElementCol);
}

void test_getScalarProductRowAndCol_notZeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    assert(getScalarProductRowAndCol(m, 1, 0) == 15);
}

void test_getScalarProductRowAndCol_zeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0, 0}, 2, 2);

    assert(getScalarProductRowAndCol(m, 0, 1) == 0);
}

void test_getSpecialScalarProductRowAndCol_notZeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    assert(getSpecialScalarProduct(m) == 15);
}

void test_getSpecialScalarProductRowAndCol_zeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0, 0}, 2, 2);

    assert(getSpecialScalarProduct(m) == 0);
}

void test_getSpecialScalarProductRowAndCol_oneElement() {
    matrix m = createMatrixFromArray((int[]) {2}, 1, 1);

    assert(getSpecialScalarProduct(m) == 4);
}

void test() {
    test_getScalarProductRowAndCol_notZeroMatrix();
    test_getScalarProductRowAndCol_zeroMatrix();
    test_getSpecialScalarProductRowAndCol_notZeroMatrix();
    test_getSpecialScalarProductRowAndCol_zeroMatrix();
    test_getSpecialScalarProductRowAndCol_oneElement();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    printf("%lld", getSpecialScalarProduct(m));

    return 0;
}
