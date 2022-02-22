#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

int getMin(int *a, int n) {
    int minElement = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] < minElement)
            minElement = a[i];

    return minElement;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement() {
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3, 2, 5, 1, 8, 2, 7, 6, 1, 4, 4, 8, 3}, 3, 6);
    matrix m2 = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4, 5, 1, 2, 2, 7, 8, 1, 4, 6, 8, 3, 4}, 3, 6);

    sortColsByMinElement(m1);

    assert(twoMatricesEqual(m1, m2));
}

void test() {
    test_sortColsByMinElement();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    sortColsByMinElement(m);

    outputMatrix(m);

    return 0;
}
