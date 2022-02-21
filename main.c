#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

bool checkIsSpecialElement(matrix m, size_t k) {
    int max = m.values[0][k];
    int sum = 0;
    for (int i = 0; i < m.nRows; ++i) {
        sum += m.values[i][k];
        if (m.values[i][k] > max)
            max = m.values[i][k];
    }

    return sum - max < max;
}

int getNSpecialElement(matrix m) {
    int count = 0;
    for (size_t i = 0; i < m.nCols; ++i)
        count += checkIsSpecialElement(m, i);

    return count;
}

int main() {
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%d", getNSpecialElement(m));

    return 0;
}
