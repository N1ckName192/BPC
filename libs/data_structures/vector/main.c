#include "vector.h"
#include <assert.h>

int main() {
    vector v = createVector(10);
    reserve(&v, 10);
    clear(&v);
    shrinkToFit(&v);
    deleteVector(&v);


    return 0;
}
