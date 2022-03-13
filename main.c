#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Libs/algorithms/functions/function.h"

#define TIME_AND_COMPS_TEST(testCode, time, comps){ \
clock_t start_time = clock(); \
 comps = (long long)testCode;\
 clock_t end_time = clock(); \
 clock_t sort_time = end_time - start_time; \
 time = (double) sort_time / CLOCKS_PER_SEC; \
 }

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                   // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64];                       // имя генератора,
    // используемое при выводе
} GeneratingFunc;

typedef struct GetNCompsFunc {
    long long (*getNComps )(int *a, size_t n);

    char name[64];
} GetNCompsFunc;

bool isOrdered(const int *a, size_t size) {
    for (int i = 0; i < size - 1; i++)
        if (a[i] > a[i + 1])
            return false;

    return true;
}

void outputArray_(const int *a, size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void checkTime(long long (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    // замер времени
    double time;
    long long comps;

    TIME_AND_COMPS_TEST({ sortFunc(innerBuffer, size) }, time, comps);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3f s.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f; %lld\n", size, time, comps);
        fclose(f);
    } else {
        printf("Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void bubbleSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = size - 1; j > i; --j)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; ++i) {
        int minPos = i;
        for (int j = i + 1; j < size; ++j)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

void insertionSort(int *a, size_t size) {
    for (int i = 1; i < size; ++i) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combsort(int *a, size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; i < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

void ShellSort(int *a, size_t size) {
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; ++i) {
            int tmp = a[i];
            size_t j;
            for (j = i; j >= step; j -= step)
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            a[j] = tmp;
        }
}

int cmp_int(const void *a, const void *b) {
    return *(const int *) a - *(const int *) b;
}

int cmp_intReverse(const void *a, const void *b) {
    return *(const int *) b - *(const int *) a;
}

void qSort(int *a, size_t size) {
    qsort(a, size, sizeof(int), cmp_int);
}

int getDigit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void digitalSort_(int *l, int *r, int N) {
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < M; ++j)
            c[j] = 0;
        for (int *j = l; j < r; ++j)
            c[getDigit(*j, i, N, M)]++;
        for (int j = 1; j < M; ++j)
            c[j] += c[j - 1];
        for (int *j = r - 1; j >= l; --j)
            b[--c[getDigit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void digitalSort(int *a, size_t n) {
    digitalSort_(a, a + n, 8);
}

void generateRandomArray(int *a, size_t size) {
    srand(time(0));
    for (int i = 0; i < size; i++)
        a[i] = rand() % 5000 - 0;
}

void generateOrderedArray(int *a, size_t size) {
    generateRandomArray(a, size);
    qsort(a, size, sizeof(int), cmp_int);
}

void generateOrderedBackwards(int *a, size_t size) {
    generateRandomArray(a, size);
    qsort(a, size, sizeof(int), cmp_intReverse);
}

long long getSelectionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

long long getBubbleSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 0; i < size - 1; ++i)
        for (int j = size - 1; j > i; --j)
            if (++nComps && a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);

    return nComps;
}

long long getInsertionSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 1; i < size; ++i) {
        int t = a[i];
        size_t j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}

long long getCombsortNComp(int *a, size_t size) {
    long long nComps = 0;
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; i < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }

    return nComps;
}

long long getShellSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = step; i < size; ++i) {
            int tmp = a[i];
            size_t j;
            for (j = i; j >= step; j -= step)
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            ++nComps;
            a[j] = tmp;
        }

    return nComps;
}

long long getDigitalSortNComp_(int *l, int *r, int N) {
    long long nComps = 0;
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < M; ++j)
            c[j] = 0;
        for (int *j = l; j < r; ++j)
            c[getDigit(*j, i, N, M)]++;
        for (int j = 1; j < M; ++j)
            c[j] += c[j - 1];
        for (int *j = r - 1; ++nComps && j >= l; --j)
            b[--c[getDigit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);

    return nComps;
}

long long getDigitalSortNComp(int *a, size_t n) {
    long long nComps = getDigitalSortNComp_(a, a + n, 8);

    return nComps;
}

long long getQSortNComps(int *a, size_t size) {
    qsort(a, size, sizeof(int), cmp_int);

    return -1;
}

void timeExperiment() {
    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    GetNCompsFunc gettingNCompsFuncs[] = {
            {getSelectionSortNComp, "selectionSort"},
            {getBubbleSortNComp,    "bubbleSort"},
            {getInsertionSortNComp, "insertionSort"},
            {getCombsortNComp,      "combsort"},
            {getDigitalSortNComp,   "digitalSort"},
            {getQSortNComps,        "qSort"},
            {getShellSortNComp,     "ShellSort"}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(gettingNCompsFuncs);

    // запись статистики в файл
    for (size_t size = 5000; size <= 50000; size += 5000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size : %zu\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        gettingNCompsFuncs[i].name, generatingFuncs[j].name);
                checkTime(gettingNCompsFuncs[i].getNComps,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

int main() {

    timeExperiment();

    return 0;
}
