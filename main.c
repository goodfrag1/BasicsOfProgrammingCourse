#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

bool isNonDescendingSorted(const int *a, int n) {
    for (size_t i = 0; i < n - 1; i++)
        if (a[i] >= a[i + 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; ++i) {
        count += hasAllNonDescendingRows(ms[i]);
    }

    return count;
}

void test_isNonDescendingSorted_false() {
    int a[] = {1, 2, 3, 4};

    assert(isNonDescendingSorted(a, 4) == true);
}

void test_isNonDescendingSorted_true() {
    int a[] = {4, 3, 2, 1};

    assert(isNonDescendingSorted(a, 4) == false);
}

void test_isNonDescendingSorted_equalElements() {
    int a[] = {1, 1, 1, 1};

    assert(isNonDescendingSorted(a, 4) == false);
}

void test_hasAllNonDescendingRows_true() {
    matrix m = createMatrixFromArray((int[]) {4, 3, 2, 1}, 2, 2);

    assert(hasAllNonDescendingRows(m) == false);
}

void test_hasAllNonDescendingRows_false() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    assert(hasAllNonDescendingRows(m) == true);
}

void test_countNonDescendingRowsMatrices_notZeroNonDescendingRowsMatrices() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 2) == 2);
}

void test_countNonDescendingRowsMatrices_zeroNonDescendingRowsMatrices() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {4, 3, 2, 1}, 2, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 2) == 0);
}

void test() {
    test_isNonDescendingSorted_true();
    test_isNonDescendingSorted_false();
    test_isNonDescendingSorted_equalElements();
    test_hasAllNonDescendingRows_true();
    test_hasAllNonDescendingRows_false();
    test_countNonDescendingRowsMatrices_notZeroNonDescendingRowsMatrices();
    test_countNonDescendingRowsMatrices_zeroNonDescendingRowsMatrices();
}

int main() {
    test();

    int nMatrices;
    scanf("%d", &nMatrices);
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    inputMatrices(ms, nMatrices);

    printf("%d", countNonDescendingRowsMatrices(ms, nMatrices));

    return 0;
}
