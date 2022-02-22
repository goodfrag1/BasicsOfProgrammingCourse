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
}

void test_getSquareOfMatrixIfSymmetric_true() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 2, 1}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {5, 4, 4, 5}, 2, 2);

    getSquareOfMatrixIfSymmetric(&m1);

    assert(twoMatricesEqual(m1, m2));
}

void test_getSquareOfMatrixIfSymmetric_false() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 3, 2);
    matrix m2 = createMatrixFromArray((int[]) {5, 4, 4, 5}, 3, 2);

    getSquareOfMatrixIfSymmetric(&m1);

    assert(!twoMatricesEqual(m1, m2));
}

void test() {
    test_getSquareOfMatrixIfSymmetric_true();
    test_getSquareOfMatrixIfSymmetric_false();
}

int main() {
    test();

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
