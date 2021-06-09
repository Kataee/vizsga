//
// Created by Kataee on 09/06/2021.
//

#include "stackDinamik.h"
void createStackD(STACKNODE** myNode) {
    (*myNode) = (STACKNODE*)malloc(1*sizeof(STACKNODE));
    if ((*myNode)==0) {
        return;
    }
    (*myNode)->next = NULL;
}

//should be done
void pushStackD(STACKNODE** topPtr, int info) {
    STACKNODE *newNode;
    createStackD(&newNode);
    newNode->info = info;
    newNode->next = (*topPtr);
    *topPtr=newNode;
}

//should be done
int topStackD(STACKNODE* topPtr) {
    if (!isEmptyStackD(topPtr)) {
        return topPtr->info;
    }
}

//should be done
int popStackD(STACKNODE** top) {
    if (isEmptyStackD(*top)) {
        return -1;
    }
    STACKNODE *aux;
    int auxinfo;
    aux = *top;
    (*top) = aux->next;
    auxinfo = aux->info;
    free(aux);
    return auxinfo;
}


//print working
void printStackD(STACKNODE* topPtr) {
    if (topPtr->next != NULL) {
        printf("%d ", topPtr -> info);
        printStackD(topPtr->next);
    }
    //printf("\n");
}

bool isEmptyStackD(STACKNODE* topPtr) {
    return topPtr == NULL;
}