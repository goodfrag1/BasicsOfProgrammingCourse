#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long scalarProduct = 0;
    for (int k = 0; k < m.nRows; ++k)
        scalarProduct += m.values[i][k] * m.values[k][j];

    return scalarProduct;
}

long long getSpecialScalarProduct(matrix m) {
    int minElementCol = getMinValuePos(m).colIndex;
    int maxElementRow = getMaxValuePos(m).rowIndex;

    return getScalarProductRowAndCol(m, maxElementRow, minElementCol);
}

int main() {
    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    printf("%lld", getSpecialScalarProduct(m));

    return 0;
}
