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

void test_getMinInArea_notEdgeMin() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6, 3, 11, 8, 9, 4, 1, 12, 2}, 3, 4);

    assert(getMinInArea(m) == 5);
}

void test_getMinInArea_edgeMin() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2, 7, 12, 3, 4, 10, 11, 5, 1}, 3, 4);

    assert(getMinInArea(m) == 6);
}

void test() {
    test_getMinInArea_edgeMin();
    test_getMinInArea_notEdgeMin();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%d", getMinInArea(m));

    return 0;
}

