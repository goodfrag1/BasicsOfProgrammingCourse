#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

int getMax(int *a, int n) {
    int maxElement = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] > maxElement)
            maxElement = a[i];
    return maxElement;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMaxElement() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1, 2, 1, 8, 1, 3, 2, 2}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {3, 2, 3, 7, 1, 2, 1, 8, 1}, 3, 3);

    sortRowsByMaxElement(m1);

    assert(twoMatricesEqual(m1, m2));
}

void test() {
    test_sortRowsByMaxElement();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    sortRowsByMaxElement(m);

    outputMatrix(m);

    return 0;
}
