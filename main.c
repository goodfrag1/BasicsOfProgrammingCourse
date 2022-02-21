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

float getMinAbs(matrixF m) {
    float minElement = m.values[0][0];
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 1; j < m.nCols; ++j)
            if (fabsf(m.values[i][j]) < minElement)
                minElement = fabsf(m.values[i][j]);

    return minElement;
}

void printMatrixWithMinAbs(matrixF *ms, int nMatrix) {
    float minAbs = ms[0].values[0][0];
    for (int i = 0; i < nMatrix; ++i)
        if (getMinAbs(ms[i]) < minAbs)
            minAbs = getMinAbs(ms[i]);

    int k = 0;
    int matrixWithMinAbsIndexes[nMatrix];
    for (int i = 0; i < nMatrix; ++i)
        if (getMinAbs(ms[i]) == minAbs) {
            matrixWithMinAbsIndexes[k] = i;
            k++;
        }


    for (int i = 0; i < k; ++i) {
        outputMatrixF(ms[matrixWithMinAbsIndexes[i]]);
        printf("\n");
    }
}

int main() {
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
