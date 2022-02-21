#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == value)
            count++;

    return count;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; ++i)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count++;

    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; ++i)
        if (countZeroRows(ms[i]) > maxZeroRows)
            maxZeroRows = countZeroRows(ms[i]);

    int k = 0;
    int matrixWithMaxZeroRowsIndexes[nMatrix];
    for (int i = 0; i < nMatrix; ++i)
        if (countZeroRows(ms[i]) == maxZeroRows) {
            matrixWithMaxZeroRowsIndexes[k] = i;
            k++;
        }

    for (int i = 0; i < k; ++i) {
        outputMatrix(ms[matrixWithMaxZeroRowsIndexes[i]]);
        printf("\n");
    }
}

int main() {
    int nMatrices;
    scanf("%d", &nMatrices);
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    inputMatrices(ms, nMatrices);

    printMatrixWithMaxZeroRows(ms, nMatrices);

    return 0;
}
