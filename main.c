#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int h = maxPos.rowIndex - 1;
    int leftBorder = maxPos.colIndex - 1;
    int rightBorder = maxPos.colIndex + 1;
    int minElement = m.values[maxPos.rowIndex][maxPos.colIndex];
    while (h >= 0) {
        for (int i = leftBorder; i < rightBorder; i++)
            if (m.values[h][i] < minElement)
                minElement = m.values[h][i];
        h--;
        leftBorder--;
        rightBorder++;
    }

    return minElement;
}

int main() {
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%d", getMinInArea(m));

    return 0;
}


