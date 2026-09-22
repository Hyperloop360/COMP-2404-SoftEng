#include "defs.h"

void initArray(int* arr) {
    for (int i = 0; i < MAX_ARR_SIZE; ++i) {
        arr[i] = random(120);
    }
}