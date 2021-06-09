//
// Created by Kataee on 07/06/2021.
//

#ifndef VIZSGA_STACK_H
#define VIZSGA_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    int maxSize; //max kapacitás
    int sp; //veremmutató
    int* year;
    int* month;
    int* day;
} STACK;

STACK* createStack(int);
bool stackIsEmpty(STACK*);
bool stackIsFull(STACK*);
void pushInStack(STACK*, int, int, int);
int* popStack(STACK*);
STACK* popStackS(STACK*);
int* topStack(STACK*);
STACK* topStackS(STACK*);
void readStack(const char*, STACK*);





#endif //VIZSGA_STACK_H
