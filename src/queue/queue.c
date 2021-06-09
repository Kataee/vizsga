//
// Created by Kataee on 08/06/2021.
//

#include "queue.h"

#include  <stdlib.h>
#include  <stdio.h>

//should be done
void createQueue(QUEUENODE** myQueue, int capacity) {
    (*myQueue) = (QUEUENODE *)malloc(1*sizeof(QUEUENODE));
    if ((*myQueue)==0) {
        return;
    }

    (*myQueue)->firstItem = true;
    (*myQueue)->front = -1;
    (*myQueue)->rear = -1;
    (*myQueue)->maxSize = capacity;
    (*myQueue)->items = (int*)malloc( (*myQueue)->maxSize * sizeof(int));
    if ((*myQueue)->items == NULL) {
        printf("Error creating myQueue.items");
        return;
    }

    printf("Queue created\n");

}

//should be done
bool isEmptyQueue(QUEUENODE* asd) {
    if (asd->front == -1) {
        return true;
    }
    return false;
}

bool isFullQueue(QUEUENODE* asd) {
    if (asd->rear == asd->maxSize-1) {
        return true;
    }
    return false;
}



void insertQueue(QUEUENODE* asd, int info) {
    if (isFullQueue(asd)) {
        printf("A sor tele van, info: %i\n", info);
        return;
    }
    if (asd->firstItem) {
        asd->front++;
        asd->firstItem = false;
    }
    asd->rear+=1;
    asd->items[asd->rear] = info;
    printf("Add last item: %i\n", asd->items[asd->rear]);
}

int removeFirstItemQueue(QUEUENODE* asd) {
    int temp;
    int item = asd->items[asd->front];
    for (int i=asd->front; i < asd->maxSize-1; ++i) {
        temp = asd->items[i+1];
        asd->items[i] = temp;
    }
    asd->rear--;
    //printQueue(asd);
    return item;
}

int topItemQueue(QUEUENODE* asd) {
    if (isEmptyQueue(asd)) {
        return -1;
    }
    printf("Top: %d\n", asd->items[asd->front]);
    return asd->items[asd->front];
}



void printQueue(QUEUENODE * asd) {
    printf("Print: ");
    for (int i=asd->front; i < asd->rear || i == 0; ++i) {
        printf("%d ", asd->items[i]);
    }
    printf("\n");
}

void fillQueue(QUEUENODE* asd) {
    for (int i=0; i < 10; ++i) {
        insertQueue(asd, i);
    }
}
