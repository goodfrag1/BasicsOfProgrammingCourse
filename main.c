#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

#define EPS 1e-8

float getDistance(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += pow(a[i], 2);

    return sqrtf(sum);
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

void test_getDistance() {
    int a[] = {1, 2, 3, 4};

    assert((getDistance(a, 4) - sqrt(30)) > EPS);
}

void test_sortByDistance() {
    matrix m1 = createMatrixFromArray((int[]) {4, 3, 2, 1}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    assert(twoMatricesEqual(m1, m2));
}

void test() {
    test_getDistance();
    test_sortByDistance();
}

int main() {
    test();

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
