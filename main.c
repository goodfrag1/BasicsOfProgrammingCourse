#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    for (int i = 1; i < m.nCols; ++i) {
        int j = i;
        int k = 0;
        int maxElement = m.values[k][j];
        while (j < m.nCols) {
            maxElement = max(maxElement, m.values[k][j]);
            j++;
            k++;
        }
        sum += maxElement;
    }
    for (int i = 1; i < m.nRows; ++i) {
        int j = i;
        int k = 0;
        int maxElement = m.values[j][k];
        while (j < m.nRows) {
            maxElement = max(maxElement, m.values[j][k]);
            j++;
            k++;
        }
        sum += maxElement;
    }

    return sum;
}

int main() {
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m));

    return 0;
}


