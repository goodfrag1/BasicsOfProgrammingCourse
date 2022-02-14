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
    for (int i = 0; i < m.nRows; ++i)
        insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int main() {
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


