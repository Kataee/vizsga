//
// Created by Kataee on 08/06/2021.
//
#include "intarray.h"

IntArray* createArray(int dimension) {
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    if (!newArray) {
        exit(1);
    }
    newArray->size = dimension;
    newArray->elements = (int*)malloc(dimension * sizeof(int));
    if (!newArray->elements) {
        exit(2);
    }
    printf("Array created, size %i\n", newArray->size);
    return newArray;
}

void readArray(const char *fileName, IntArray **array) {

    FILE *f;  //file stream

    //check if file can be opened
    if ((f= fopen(fileName, "r")) == NULL) {
        printf("Error opening file");
        exit(3);
    }

    //read
    for (int i=0; i < (*array)->size; ++i) {
        //if end of file, return
        if (feof(f)) {
            printf("End of file\n");
            realloc((*array)->elements, i);
            (*array)->size = i;
            printf("Array reallocated, size %i\n", (*array)->size);
            return;
        }
        fscanf(f, "%i", &(*array)->elements[i]);
        printf("%i ", (*array)->elements[i]);
    }
    fclose(f);
}

void fillArray(int* array, int dimension, int first, int last) {
    srand(time(0));
    for (int i=0; i<dimension; ++i) {
        array[i] = rand() % (last - first) + first;
    }
}

void printArray(IntArray* array) {
    for (int i=0; i< array->size; ++i) {
        printf("%i ", (*array).elements[i]);
    }
    printf("\n");
}


void printArrayToFile(const char* fileName, IntArray *array) {
    FILE *f;  //file stream

    //check if file can be opened
    if ((f= fopen(fileName, "w")) == NULL) {
        printf("Error opening file");
        exit(7);
    }
    for (int i=0; i<array->size; ++i) {
        fprintf(f, "%i ", array->elements[i]);
    }
    printf("success\n");
    fclose(f);
}

void sortArray(IntArray *array) {
    qsort(array->elements, array->size, sizeof(int), compareFunc); //rendezes
}
int compareFunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findElement(IntArray *array, int element) {

    for (int i=0; i < array->size; ++i) {
        if (array->elements[i] == element) {
            printf("A keresett elem %i, a poz: %i\n", element,i);
            return i;
        }
    }
    printf("Aaaa keresett elem %i, a poz: %i\n", element, -1);
    return -1;
}


void deleteElement(IntArray *array, int element) {
    int temp;
    while (findElement(array, element) != -1) {
        for (int i = findElement(array, element); i < array->size-1; ++i) {
            array->elements[i] = array->elements[i+1];
        }
        array->size--;
        //realloc(array->elements , array->size);  //how to realloc here?
        printf("Deleted, size: %i\n", array->size);
    }
}


int minimum(IntArray* array) {
    int min = array->elements[0];
    for (int i=0; i < array->size; ++i) {
        if (array->elements[i] < min) {
            min = array->elements[i];
        }
    }
    return min;
}

int maximum(IntArray* array) {
    int max = array->elements[0];
    for (int i=0; i < array->size; ++i) {
        if (array->elements[i] > max) {
            max = array->elements[i];
        }
    }
    return max;
}

void copy(IntArray* arrayTo, IntArray* arrayFrom) {
    if (arrayTo->size == arrayFrom->size) {
        for ( int i=0; i < arrayTo ->size; ++i) {
            arrayTo->elements[i] = arrayFrom->elements[i];
        }
    } else {
        printf("Cannot copy, size not equal\n");
    }
}

int linearSearch(IntArray* array, int element) {
    for (int i=0; i < array->size; ++i) {
        if (element == array->elements[i]) {
            return element;
        }
    }
    printf("There is no such element\n");
    return -1;
}

int binarySearch(IntArray* array, int start, int end, int element) {
    int middle = (start + end) / 2;
    if(end < start) {
        return -1;
    }
    if(element==array->elements[middle]) {
        //printf("BS: A %i szam megtalalva", target);
        return element;
    } else if(element<array->elements[middle]) {
        return binarySearch(array, start, middle - 1, element);
    } else {
        return binarySearch(array, middle + 1, end, element);
    }
}