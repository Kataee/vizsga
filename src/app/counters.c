#include "counters.h"

counters_t __counters = {0, 0};

void c_reset() {
    __counters.comparisons = 0;
    __counters.operations = 0;
}

void c_op_add(int x) {
    __counters.operations += x;
}

void c_cm_add(int x) {
    __counters.comparisons += x;
}

void c_op_inc() {
    c_op_add(1);
}

void c_cm_inc() {
    c_cm_add(1);
}

counters_t c_get() {
    return __counters;
}
