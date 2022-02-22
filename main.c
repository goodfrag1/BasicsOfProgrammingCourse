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

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

void test_isMutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    transposeSquareMatrix(m2);

    assert(twoMatricesEqual(m1, m2));
}

void test_mulMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {4, 3, 2, 1}, 2, 2);

    matrix resM = createMatrixFromArray((int[]) {8, 5, 20, 13}, 2, 2);

    assert(twoMatricesEqual(resM, mulMatrices(m1, m2)));
}

void test() {
    test_mulMatrices();
    test_isMutuallyInverseMatrices();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);

    matrix A = getMemMatrix(nRows, nRows);
    inputMatrix(A);
    matrix B = getMemMatrix(nRows, nRows);
    inputMatrix(B);

    printf("%d", isMutuallyInverseMatrices(A, B));

    return 0;
}

