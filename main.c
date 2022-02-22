#include <stdio.h>
#include "Libs/data_structures/matrix/matrix.h"
#include "Libs/algorithms/functions/function.h"

long long getSum(const int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    return sum;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long *) pa;
    long long arg2 = *(const long *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    int count = 1;
    long long previous = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] != previous) {
            count++;
            previous = a[i];
        }

    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long arrayOfSums[m.nRows];
    for (int i = 0; i < m.nRows; ++i)
        arrayOfSums[i] = getSum(m.values[i], m.nCols);

    qsort(arrayOfSums, m.nRows, sizeof(long long), cmp_long_long);

    return countNUnique(arrayOfSums, m.nRows);
}

void test_NUnique_notOneElement() {
    long long a[] = {1, 2, 3, 4};

    assert(countNUnique(a, 4) == 4);
}

void test_NUnique_oneElement() {
    long long a[] = {1};

    assert(countNUnique(a, 1) == 1);
}

void test_NUnique_noUniqueElements() {
    long long a[] = {1, 1, 1, 1};

    assert(countNUnique(a, 4) == 1);
}

void test_countEqClassesByRowsSum_diffClasses() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2, 7, 5, 4, 4, 3, 1, 6, 8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 3);
}

void test_countEqClassesByRowsSum_similarClasses() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 1, 7, 5, 3, 4, 4, 2, 6, 8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 1);
}

void test() {
    test_NUnique_noUniqueElements();
    test_NUnique_notOneElement();
    test_NUnique_oneElement();
    test_countEqClassesByRowsSum_diffClasses();
    test_countEqClassesByRowsSum_similarClasses();
}

int main() {
    test();

    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%d", countEqClassesByRowsSum(m));

    return 0;
}
