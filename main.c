#include <stdio.h>
#include "Libs/algorithms/functions/function.h"
#include "Libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(4);
    reserve(&v, SIZE_MAX);

    return 0;
}
