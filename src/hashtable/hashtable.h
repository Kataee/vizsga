#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct hashtable {
    char** table;
    int capacity, elements;
} hashtable_t;

hashtable_t* hashtable_create(int capacity);
void hashtable_add(hashtable_t* hash, char* s); //add element to the hash
void hashtable_print(hashtable_t* array); //print the strings to the console
void hashtable_delete(hashtable_t* hash, char* s); //delete string
char* hashtable_search(hashtable_t* hash, char* s);

#endif //__HASHTABLE_H
