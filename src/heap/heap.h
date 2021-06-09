//
// Created by Kataee on 09/06/2021.
//

#ifndef VIZSGA_HEAP_H
#define VIZSGA_HEAP_H

#endif //VIZSGA_HEAP_H
typedef struct {
    int* data;
    int size;
    int maxSize;
}HEAP;

HEAP *createHeap(int max);
void insertHeap(HEAP* h, int Element);
void upHeap (HEAP* h, int i);
void downHeap(HEAP*, int);
void down2Heap(HEAP*, int);
void kupacrendez(HEAP* h);
void kupacrendezNoDelete(HEAP* h);

int torolmax (HEAP *h);

void swap(int*, int*);

HEAP* two(HEAP*, HEAP*);
void printHeap(HEAP*);

//###############################
//EUR

void fel22();
