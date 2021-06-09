//
// Created by Kataee on 09/06/2021.
//

#ifndef VIZSGA_STACKDINAMIK_H
#define VIZSGA_STACKDINAMIK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
    struct NodeType *next;
}STACKNODE;

void createStackD(STACKNODE**);
void pushStackD(STACKNODE**, int);
int topStackD(STACKNODE*);
int popStackD(STACKNODE** );
bool isEmptyStackD(STACKNODE *);
void printStackD(STACKNODE*);


#endif //VIZSGA_STACKDINAMIK_H
