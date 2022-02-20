#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

float getDistance(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += pow(a[i], 2);

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *resultsOfCriteria = (float *) malloc(m.nRows * sizeof(float));
    for (int i = 0; i < m.nRows; ++i)
        resultsOfCriteria[i] = criteria(m.values[i], m.nCols);
    for (int i = 0; i < m.nRows; ++i) {
        int index = i;
        while (resultsOfCriteria[index] < resultsOfCriteria[index - 1] && index > 0) {
            swapF(&resultsOfCriteria[index], &resultsOfCriteria[index - 1]);
            swapRows(m, index, index - 1);
            index--;
        }
    }
    free(resultsOfCriteria);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int main() {
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    sortByDistances(m);

    outputMatrix(m);

    return 0;
}
