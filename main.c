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
        for (int j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                return false;

    return true;
}

void transposeIfMatrixHasEqualSumOfRows(matrix *m, int nRows, int nCols) {
    long long arrayOfSums[m->nRows];
    for (int i = 0; i < m->nRows; ++i)
        arrayOfSums[i] = getSum(m->values[i], m->nRows);

    if (!isUnique(arrayOfSums, nRows)) {
        transposeSquareMatrix(*m);
        outputMatrix(*m);
    } else
        printf("NO UNIQUE SUMS");
}

int main() {
    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    transposeIfMatrixHasEqualSumOfRows(&m, m.nRows, m.nCols);

    return 0;
}


