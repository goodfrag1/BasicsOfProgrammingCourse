#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

position getLeftMin(matrix m) {
    return getMinValuePos(m);
}

void swapPenultimateRow(matrix m) {
    position minElementPos = getLeftMin(m);
    int minElementCol = minElementPos.colIndex;
    for (int i = m.nRows - 1; i >= 0; --i)
        m.values[m.nRows - 2][i] = m.values[i][minElementCol];
}

int main() {
    int nRows;
    scanf("%d", &nRows);

    matrix m = getMemMatrix(nRows, nRows);
    inputMatrix(m);

    swapPenultimateRow(m);

    outputMatrix(m);

    return 0;
}
