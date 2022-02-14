#include "matrix.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int *getColumn(matrix m, int i) {
    int *column = (int *) malloc(m.nRows * sizeof(int));
    for (int j = 0; j < m.nRows; ++j)
        column[j] = m.values[j][i];

    return column;
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i <= nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
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
    for (int i = 0; i < m.nRows; ++i) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *resultsOfCriteria = (int *) malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; ++i)
        resultsOfCriteria[i] = criteria(m.values[i], m.nCols);
    for (int i = 0; i < m.nRows; ++i) {
        int index = i;
        while (resultsOfCriteria[index] < resultsOfCriteria[index - 1] && index > 0) {
            swap(&resultsOfCriteria[index], &resultsOfCriteria[index - 1]);
            swapRows(m, index, index - 1);
            index--;
        }
    }
    free(resultsOfCriteria);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *resultsOfCriteria = (int *) malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nCols; ++i) {
        int *column = getColumn(m, i);
        resultsOfCriteria[i] = criteria(column, m.nRows);
    }
    for (int i = 0; i < m.nCols; ++i) {
        int index = i;
        while (resultsOfCriteria[index] < resultsOfCriteria[index - 1] && index > 0) {
            swap(&resultsOfCriteria[index], &resultsOfCriteria[index - 1]);
            swapColumns(m, index, index - 1);
            index--;
        }
    }
    free(resultsOfCriteria);
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
    for (int i = 0; i < m.nRows; ++i)
        for (int j = i; j < m.nCols; ++j) {
            int t = m.values[i][j];
            m.values[i][j] = m.values[j][i];
            m.values[j][i] = t;
        }
}

position getMinValuePos(matrix m) {
    position minIndex;
    minIndex.colIndex = 0;
    minIndex.rowIndex = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] < m.values[minIndex.rowIndex][minIndex.colIndex]) {
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
