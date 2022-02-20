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
    return memcmp(pa, pb, sizeof(long long));
}

int countNUnique(long long *a, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < i && cmp_long_long(a + j, a + i))
            j++;
        count += j == i;
    }

    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long arrayOfSums[m.nRows];
    for (int i = 0; i < m.nRows; ++i)
        arrayOfSums[i] = getSum(m.values[i], m.nCols);
    int countOfUnique = countNUnique(arrayOfSums, m.nRows);

    return countOfUnique;
}

int main() {
    int nRows;
    scanf("%d", &nRows);
    int nCols;
    scanf("%d", &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    printf("%d", countEqClassesByRowsSum(m));

    return 0;
}
