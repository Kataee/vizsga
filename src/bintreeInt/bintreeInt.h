//
// Created by Kataee on 09/06/2021.
//

#ifndef VIZSGA_BINTREEINT_H
#define VIZSGA_BINTREEINT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct BintreeInt {
    int info;
    struct BintreeInt *left, *right;
} BintreeInt;

BintreeInt* createBintreeInt();
BintreeInt* insertBintreeInt (BintreeInt**, int);
void inorder(BintreeInt*);
void preorder(BintreeInt*);
void postorder(BintreeInt*);

bool findBintreeInt(struct BintreeInt* , int);
struct BintreeInt* deleteNodeBintreeInt(struct BintreeInt*, int);
struct BintreeInt* deleteBintreeInt(BintreeInt*, int);
struct BintreeInt* minValueNodeBintreeInt(struct BintreeInt* );
struct BintreeInt* maxValueNodeBintreeInt(struct BintreeInt* );

struct BintreeInt* nextNodeBintreeInt(struct BintreeInt*);
struct BintreeInt* parentBintreeInt (struct BintreeInt*, int);


void fel2();
int findMax(int*, int);
int hasValue(int*, int, int);
void print(int*, int);

#endif //VIZSGA_BINTREEINT_H
