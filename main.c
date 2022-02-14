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

int main() {
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


