//
// Created by Kataee on 09/06/2021.
//

#ifndef VIZSGA_QUEUEDINAMIK_H
#define VIZSGA_QUEUEDINAMIK_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int info;
    struct QUEUENODED *next;
}QUEUENODED;
QUEUENODED *queueDFront = NULL, *queueDLast = NULL;

bool isQueueDEmpty(QUEUENODED*);
void createQueueD(QUEUENODED**);
void insertQueueD(QUEUENODED**, QUEUENODED**, int);
int deleteFirstQueueD(QUEUENODED**);
void printQueueD(QUEUENODED*);





#endif //VIZSGA_QUEUEDINAMIK_H
