#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

void test_getMemMatrix_notVoidMatrix() {
    matrix m = getMemMatrix(2, 2);

    assert(m.nRows == 2);
    assert(m.nCols == 2);
    freeMemMatrix(m);
}

void test_getMemMatrix_voidMatrix() {
    matrix m = getMemMatrix(0, 0);

    assert(m.nRows == 0);
    assert(m.nCols == 0);
    freeMemMatrix(m);
}

void test_inputMatrix_notVoidMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    matrix m2 = getMemMatrix(2, 2);
    inputMatrix(m2);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_inputMatrix_voidMatrix() {
    matrix m1 = getMemMatrix(0, 0);
    matrix m2 = getMemMatrix(0, 0);

    inputMatrix(m2);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMemArrayOfMatrices_notVoidMatrices() {
    matrix *ms = getMemArrayOfMatrices(2, 2, 2);

    assert(ms[0].nRows == 2);
    assert(ms[1].nCols == 2);
    freeMemMatrices(ms, 2);
}

void test_getMemArrayOfMatrices_voidMatrices() {
    matrix *ms = getMemArrayOfMatrices(0, 0, 0);

    assert(ms[0].nRows == 0);
    assert(ms[0].nCols == 0);
    freeMemMatrices(ms, 0);
}

void test_inputMatrices_notVoidMatrices() {
    matrix *ms1 = createArrayOfMatrixFromArray((int[]) {1, 2, 3, 4, 1, 2, 3, 4}, 2, 2, 2);

    matrix *ms2 = getMemArrayOfMatrices(2, 2, 2);
    inputMatrices(ms2, 2);

    assert(twoMatricesEqual(ms1[0], ms2[0]));
    assert(twoMatricesEqual(ms1[1], ms2[1]));
    freeMemMatrices(ms1, 2);
    freeMemMatrices(ms2, 2);
}

void test_inputMatrices_voidMatrices() {
    matrix *ms1 = createArrayOfMatrixFromArray((int[]) {}, 0, 0, 0);

    matrix *ms2 = getMemArrayOfMatrices(0, 0, 0);
    inputMatrices(ms2, 0);

    assert(twoMatricesEqual(ms1[0], ms2[0]));
    freeMemMatrices(ms1, 0);
    freeMemMatrices(ms2, 0);
}

void test_swapRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {3, 4, 1, 2}, 2, 2);
    swapRows(m1, 0, 1);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapColumns() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, 1, 4, 3}, 2, 2);
    swapColumns(m1, 0, 1);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isSquareMatrix_true() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix_false() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 2, 3);

    assert(!isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_notZeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 1}, 2, 2);

    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_zeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0, 0}, 2, 2);

    assert(!isEMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_notZeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 2, 1}, 2, 2);

    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_zeroMatrix() {
    matrix m = createMatrixFromArray((int[]) {0, 0, 0, 0}, 2, 2);

    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    transposeSquareMatrix(m1);
    matrix m2 = createMatrixFromArray((int[]) {1, 3, 2, 4}, 2, 2);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMinValuePos_nonEqualElements() {
    matrix m = createMatrixFromArray((int[]) {2, 4, 1, 3}, 2, 2);
    position pos = getMinValuePos(m);

    assert(pos.rowIndex == 1);
    assert(pos.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMinValuePos_equalElements() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1}, 2, 2);
    position pos = getMinValuePos(m);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMaxValuePos_nonEqualElements() {
    matrix m = createMatrixFromArray((int[]) {2, 4, 1, 3}, 2, 2);
    position pos = getMaxValuePos(m);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 1);
    freeMemMatrix(m);
}

void test_getMaxValuePos_equalElements() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 1}, 2, 2);
    position pos = getMaxValuePos(m);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 0);
    freeMemMatrix(m);
}

void test() {
    // 1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4
    test_getMemMatrix_notVoidMatrix();
    test_getMemMatrix_voidMatrix();
    test_inputMatrix_notVoidMatrix();
    test_inputMatrix_voidMatrix();
    test_getMemArrayOfMatrices_notVoidMatrices();
    test_getMemArrayOfMatrices_voidMatrices();
    test_inputMatrices_notVoidMatrices();
    test_inputMatrices_voidMatrices();
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix_true();
    test_isSquareMatrix_false();
    test_isEMatrix_notZeroMatrix();
    test_isEMatrix_zeroMatrix();
    test_isSymmetricMatrix_notZeroMatrix();
    test_isSymmetricMatrix_zeroMatrix();
    test_transposeSquareMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos_nonEqualElements();
    test_getMinValuePos_equalElements();
    test_getMaxValuePos_nonEqualElements();
    test_getMaxValuePos_equalElements();
}

int main() {
    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    position minValuePos = getMinValuePos(m);
    position maxValuePos = getMaxValuePos(m);
    swapRows(m, maxValuePos.rowIndex, minValuePos.rowIndex);

    outputMatrix(m);

    return 0;
}


