#ifndef __COUNTERS_H
#define __COUNTERS_H

typedef struct counters {
    int operations;
    int comparisons;
} counters_t;

void c_reset();
void c_op_add(int x);
void c_cm_add(int x);
void c_op_inc();
void c_cm_inc();
counters_t c_get();

#endif // __COUNTERS_H
