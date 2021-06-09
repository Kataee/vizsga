//
// Created by Kataee on 08/06/2021.
//

#ifndef VIZSGA_SET_H
#define VIZSGA_SET_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int size;
    int* elements;
}Set;

int cmpfunc (const void *, const void *);
//void qsort(int*, int, int, int);
void printElements(Set set);
Set* createSet(Set*);
int size(Set);
bool isEmpty (Set);
void insert(Set*, int);
void erase(Set*, int);
void erasePos(Set*, int);
void clear(Set*);
int find(Set, int);
int lowerBound(Set, int);
int upperBound(Set, int);

void uniteSet(Set*, Set*, Set* );
void crossSection(Set*, Set*, Set*);
void substraction(Set*, Set*, Set*);
void subset(Set*, Set*, int, int);



#endif //VIZSGA_SET_H
