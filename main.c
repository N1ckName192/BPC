#include "libs/data_structures/vector/vector.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector v = createVector(5);

    printf("capacity: %zu, size: %zu, data: %zu\n", v.capacity, v.size, v.data);

    reserve(&v, 10);

    printf("capacity: %zu, size: %zu, data: %zu\n", v.capacity, v.size, v.data);

    clear(&v);

    printf("capacity: %zu, size: %zu, data: %zu\n", v.capacity, v.size, v.data);

    shrinkToFit(&v);

    printf("capacity: %zu, size: %zu, data: %zu\n", v.capacity, v.size, v.data);

    deleteVector(&v);

    printf("capacity: %zu, size: %zu, data: %zu\n", v.capacity, v.size, v.data);

    return 0;
}
