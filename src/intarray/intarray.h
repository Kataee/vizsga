//
// Created by Kataee on 08/06/2021.
//

#ifndef VIZSGA_INTARRAY_H
#define VIZSGA_INTARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int size;
    int *elements;
} IntArray;

//létrehozás
IntArray* createArray(int dimension);

//beolvasás
void readArray(const char *fileName, IntArray **array);

//véletlen számokkal feltöltés
void fillArray(int* array, int dimension, int first, int last);

//a tömb kiírása a képernyőre
void printArray(IntArray* array);

//file kiírása állományba
void printArrayToFile(const char* fileName, IntArray *array);

//tömb elemeinek sorrendbe rendezése, ezesetben növekvő
void sortArray(IntArray *array);
int compareFunc(const void* a, const void* b);

//elem keresése lineáris vagy bináris kereséssel, pozíciót térít vissza
int findElement(IntArray *array, int element);

//egy elem törlése
void deleteElement(IntArray *array, int element);

//legkisebb elem
int minimum(IntArray* array);


//legnagyobb elem
int maximum(IntArray* array);

//tömb másolása, de csak ha a hossz egyenlő
void copy(IntArray* arrayTo, IntArray* arrayFrom);


//lineáris keresés
int linearSearch(IntArray* array, int element);


//bináris keresés
int binarySearch(IntArray* array, int start, int end, int element);


#endif //VIZSGA_INTARRAY_H
