#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

matrix mulMatrices(matrix m1, matrix m2) {
    matrix resM = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; ++i)
        for (int j = 0; j < m2.nCols; ++j) {
            resM.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; ++k)
                resM.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return resM;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
};

int main() {
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    getSquareOfMatrixIfSymmetric(&m);

    if (isSymmetricMatrix(m))
        outputMatrix(m);
    else
        printf("NOT SYMMETRIC MATRIX");

    return 0;
}


