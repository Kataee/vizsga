//
// Created by Kataee on 09/06/2021.
//

#include "queueDinamik.h"

bool isQueueDEmpty(QUEUENODED* asd) {
    if (queueDFront == NULL) {
        return true;
    }
    return false;
}

void createQueueD(QUEUENODED** asd) {
    (*asd) = (QUEUENODED*)malloc(1*sizeof(QUEUENODED));
    if ((*asd) == NULL) {
        return;
    }
    (*asd)->next = NULL;
    printf("Queue dinamik created\n");

}

void insertQueueD(QUEUENODED** front, QUEUENODED** last, int info) {
    QUEUENODED* newNode;
    createQueueD(&newNode);
    newNode->info = info;
    if (isQueueDEmpty(newNode)) {
        *front = newNode;
        *last = newNode;
    } else {
        (*last)->next = newNode;
    }
    *last = newNode;
    printf("Insert: %i\n", newNode->info);
}

int deleteFirstQueueD(QUEUENODED** front) {
    if (isQueueDEmpty(*front)) {
        printf("QueueD is empty, cannot delete\n");
        return INT_MIN;
    }
    QUEUENODED* auxNode =  &front;
    int auxInfo = (*front)->info;

    (*front) = (*front)->next;
    free(auxNode); //error
    printf("Deleted front: %i\n", auxInfo);
    return auxInfo;
}

void printQueueD(QUEUENODED* next) {
    if (isQueueDEmpty(next)) {
        printf("Queue is empty, cannot print\n");
        return;
    }
    printf("%d ", next->info);
    if (next->next == NULL) {
        return;
    }
    printQueueD(next->next);

}
