#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nCols; ++i)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            printf("%d", m.values[i][j]);
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows - 1; ++i) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {

}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {

}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (isSquareMatrix(m1) && isSquareMatrix(m2)) {
        for (int i = 0; i < m1.nCols; ++i)
            for (int j = 0; j < m1.nRows; ++j)
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
    } else
        return false;

    return true;
}

bool isEMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (!((i == j && m.values[i][j] == 1) || (i != j && m.values[i][j] == 0)))
                return false;

    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (int i = 0; i < m.nRows; ++i)
            for (int j = 0; j < m.nCols; ++j)
                if (i != m.nCols && m.values[i][j] != m.values[j][i])
                    return false;
    } else
        return false;

    return true;
}

void transposeSquareMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (int i = 0; i < m.nRows; ++i)
            for (int j = i; j < m.nCols; ++j) {
                int t = m.values[i][j];
                m.values[i][j] = m.values[j][i];
                m.values[j][i] = t;
            }
    }
}

position getMinValuePos(matrix m) {
    position minIndex;
    minIndex.colIndex = 0;
    minIndex.rowIndex = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 1; j < m.nCols; ++j)
            if (m.values[i][j] <= m.values[minIndex.rowIndex][minIndex.colIndex]) {
                minIndex.rowIndex = i;
                minIndex.colIndex = j;
            }
    return minIndex;
}

position getMaxValuePos(matrix m) {
    position maxIndex;
    maxIndex.colIndex = 0;
    maxIndex.rowIndex = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 1; j < m.nCols; ++j)
            if (m.values[i][j] > m.values[maxIndex.rowIndex][maxIndex.colIndex]) {
                maxIndex.rowIndex = i;
                maxIndex.colIndex = j;
            }
    return maxIndex;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

