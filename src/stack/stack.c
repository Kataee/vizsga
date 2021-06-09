//
// Created by Kataee on 07/06/2021.
//

#include "stack.h"
STACK* createStack(int maxSize) {
    STACK* node = (STACK*)malloc(sizeof(STACK));
    if (node == NULL) {
        printf("Error creating stack node");
        return NULL;
    }

    node->sp = -1;
    node->maxSize = maxSize;

    node->year = (int*)malloc(maxSize*sizeof(int));
    if (node->year == NULL) {
        printf("Error creating elements");
        return NULL;
    }

    node->month = (int*)malloc(maxSize*sizeof(int));
    if (node->month == NULL) {
        printf("Error creating elements");
        return NULL;
    }

    node->day = (int*)malloc(maxSize*sizeof(int));
    if (node->day == NULL) {
        printf("Error creating elements");
        return NULL;
    }

    //printf("Stack created successfully\n");
    return node;
}

bool stackIsEmpty(STACK* node) {
    if (node->sp == -1) {
        return true;
    }
    return false;
}
bool stackIsFull(STACK* node) {
    if (node->sp == node->maxSize-1) {
        return true;
    }
    return false;
}

void pushInStack(STACK* node, int year, int month, int day) {
    if (!stackIsFull(node)) {
        node->sp++;
        node->year[node->sp] = year;
        node->month[node->sp] = month;
        node->day[node->sp] = day;
    }
    //printf("Elem beteve: %i %i %i... sp: %i\n", node->year[node->sp],
     //                                       node->month[node->sp],
      //                                      node->day[node->sp], node->sp);
}

int* popStack(STACK* node) {
    if (!stackIsFull(node)) {
        int year = node->year[node->sp];
        int month = node->month[node->sp];
        int day = node->day[node->sp];
        node->sp--;
        int* items = (int*)malloc(3*sizeof(int));
        items[0] = year;
        items[1] = month;
        items[2] = day;
        return &*items;
    }
    return NULL;
}

STACK* popStackS(STACK* node) {
    if (!stackIsFull(node)) {
        STACK* temp = createStack(1);
        pushInStack(temp, node->year[node->sp],node->month[node->sp],node->day[node->sp]);
        node->sp--;
        return temp;
    }
    return NULL;
}
/*
int topStack(STACK* node) {
    if (!stackIsFull(node)) {
        return node->items[node->sp];
    }
}*/
STACK* topStackS(STACK* node) {
    if (!stackIsFull(node)) {
        STACK* temp = createStack(1);
        pushInStack(temp, node->year[node->sp],node->month[node->sp],node->day[node->sp]);
        return temp;
    }
    return NULL;
}

void readStack(const char* fileName, STACK* node) {
    FILE *f; //file stream
    int year, month, day, count=0;

    // check if file can be opened
    if ((f = fopen(fileName, "r")) == NULL) {
        printf("Error opening file"); exit(4);
    }

    for (int i=0; i < node->maxSize; ++i) {
        if (feof(f)) {
            printf("End of file\n");
            fclose(f);
            return;
        }
        fscanf(f, "%i", &year);
        fscanf(f, "%i", &month);
        fscanf(f, "%i", &day);

        if (year < 1900 || year > 2000) {
            count++;
            if (count >= 5) { break; }
            continue;
        }
        pushInStack(node, year, month, day);
        printf("%i %i %i\n", node->year[node->sp], node->month[node->sp], node->day[node->sp]);
    }
}


