#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

long long getSum(const int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    return sum;
}

bool isUnique(const long long *a, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n - 1; ++j)
            if (a[i] == a[j])
                return false;

    return true;
}

void transposeIfMatrixHasEqualSumOfRows(matrix m, int nRows, int nCols) {
    long long arrayOfSums[m.nRows];
    for (int i = 0; i < m.nRows; ++i)
        arrayOfSums[i] = getSum(m.values[i], m.nRows);

    if (!isUnique(arrayOfSums, nRows))
        transposeSquareMatrix(m);
}

void test_getSum() {
    int a[] = {1, 2, 3, 4};

    assert(getSum(a, 4) == 10);
}

void test_isUnique_true() {
    long long a[] = {1, 2, 3, 4};

    assert(isUnique(a, 4));
}

void test_isUnique_false() {
    long long a[] = {1, 1, 3, 4};

    assert(!isUnique(a, 4));
}

void test_transposeIfMatrixHasEqualSumOfRows_equalSum() {
    matrix m1 = createMatrixFromArray((int[]) {1, 6, 3, 4}, 2, 2);
    transposeIfMatrixHasEqualSumOfRows(m1, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {3, 1, 6, 4}, 2, 2);

    assert(twoMatricesEqual(m1, m2));
}

void test_transposeIfMatrixHasEqualSumOfRows_notEqualSum() {
    matrix m1 = createMatrixFromArray((int[]) {1, 5, 3, 4}, 2, 2);
    transposeIfMatrixHasEqualSumOfRows(m1, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {1, 5, 3, 4}, 2, 2);

    assert(twoMatricesEqual(m1, m2));
}

void test() {
    test_getSum();
    test_isUnique_true();
    test_isUnique_false();
    test_transposeIfMatrixHasEqualSumOfRows_equalSum();
    test_transposeIfMatrixHasEqualSumOfRows_notEqualSum();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    transposeIfMatrixHasEqualSumOfRows(m, m.nRows, m.nCols);

    outputMatrix(m);

    return 0;
}
