#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

typedef struct matrixF {
    float **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrixF;

matrixF getMemMatrixF(int nRows, int nCols) {
    float **values = (float **) malloc(sizeof(float *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (float *) malloc(sizeof(float) * nCols);

    return (matrixF) {values, nRows, nCols};
}

matrixF *getMemArrayOfMatricesF(int nMatrices, int nRows, int nCols) {
    matrixF *ms = (matrixF *) malloc(sizeof(matrixF) * nMatrices);
    for (int i = 0; i <= nMatrices; i++)
        ms[i] = getMemMatrixF(nRows, nCols);

    return ms;
}

void inputMatrixF(matrixF m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            scanf("%f", &m.values[i][j]);
}

void inputMatricesF(matrixF *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrixF(ms[i]);
}

void outputMatrixF(matrixF m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%f ", m.values[i][j]);
        printf("\n");
    }
}

matrixF createMatrixFromArrayF(const float *a, size_t nRows, size_t nCols) {
    matrixF m = getMemMatrixF(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

float getMaxAbs(matrixF m) {
    float maxElement = fabsf(m.values[0][0]);
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 1; j < m.nCols; ++j)
            if (fabsf(m.values[i][j]) > maxElement)
                maxElement = fabsf(m.values[i][j]);

    return maxElement;
}

float getMinAbs(matrixF m) {
    float minElement = fabsf(m.values[0][0]);
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 1; j < m.nCols; ++j)
            if (fabsf(m.values[i][j]) < minElement)
                minElement = fabsf(m.values[i][j]);

    return minElement;
}

float findMinElement(const float *a, const size_t n) {
    float minElement = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] < minElement)
            minElement = a[i];

    return minElement;
}

void printMatrixWithMinAbs(matrixF *ms, int nMatrix) {
    float maxAbs[nMatrix];
    for (int i = 0; i < nMatrix; ++i)
        maxAbs[i] = getMaxAbs(ms[i]);

    float minAbs = findMinElement(maxAbs, nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        if (maxAbs[i] == minAbs) {
            outputMatrixF(ms[i]);
            printf("\n");
        }
}

void test_getMinAbs_zeroMatrix() {
    matrixF m = createMatrixFromArrayF((float[]) {0, 0, 0, 0}, 2, 2);

    assert(getMinAbs(m) == 0);
}

void test_getMinAbs_notZeroMatrix() {
    matrixF m = createMatrixFromArrayF((float[]) {-1, 2, 3, 4}, 2, 2);

    assert(getMinAbs(m) == 1);
}

void test_getMinAbs_oneElement() {
    matrixF m = createMatrixFromArrayF((float[]) {-4}, 1, 1);

    assert(getMinAbs(m) == 4);
}

void test_getMaxAbs_zeroMatrix() {
    matrixF m = createMatrixFromArrayF((float[]) {0, 0, 0, 0}, 2, 2);

    assert(getMaxAbs(m) == 0);
}

void test_getMaxAbs_notZeroMatrix() {
    matrixF m = createMatrixFromArrayF((float[]) {-1, 2, 3, -4}, 2, 2);

    assert(getMaxAbs(m) == 4);
}

void test_getMaxAbs_oneElement() {
    matrixF m = createMatrixFromArrayF((float[]) {-4}, 1, 1);

    assert(getMaxAbs(m) == 4);
}

void test() {
    test_getMinAbs_zeroMatrix();
    test_getMinAbs_notZeroMatrix();
    test_getMinAbs_oneElement();
    test_getMaxAbs_notZeroMatrix();
    test_getMaxAbs_zeroMatrix();
    test_getMaxAbs_oneElement();
}

int main() {
    test();

    int nMatrices;
    scanf("%d", &nMatrices);
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrixF *ms = getMemArrayOfMatricesF(nMatrices, nRows, nCols);
    inputMatricesF(ms, nMatrices);

    printMatrixWithMinAbs(ms, nMatrices);

    return 0;
}
