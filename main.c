#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows + m.nCols - 1;
    int *maxElements = (int *) (calloc(n, sizeof(int)));

    int index = m.nRows - 1;
    long long sum = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (i != j) {
                int k = index - i + j;
                if (i == 0 || j == 0)
                    maxElements[k] = m.values[i][j];
                else
                    maxElements[k] = max(maxElements[k], m.values[i][j]);
            }

    for (int i = 0; i < n; ++i)
        sum += maxElements[i];

    return sum;
}

void test_findSumOfMaxesOfPseudoDiagonal_notOneElement() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4, 1, 3, 6, 3, 3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneElement() {
    matrix m = createMatrixFromArray((int[]) {3}, 1, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 0);
}

void test() {
    test_findSumOfMaxesOfPseudoDiagonal_notOneElement();
    test_findSumOfMaxesOfPseudoDiagonal_oneElement();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m));

    return 0;
}

