#ifndef __WORDARRAY_H
#define __WORDARRAY_H

#include <stdbool.h>

typedef struct wordarray {
    int size, rear;
    char **words;
} wordarray_t;

wordarray_t *wordarray_create();
void wordarray_load(const char *fileName, wordarray_t *array); //read strings from file into char* 2dimension array
void wordarray_print(wordarray_t *array); //print the strings to the console
bool wordarray_add(wordarray_t *array, char *word);     //add new string to the end
int wordarray_search(wordarray_t *array, char *word);     //search a string and return it
int wordarray_count(wordarray_t *array);       //return the number of strings
bool wordarray_delete(wordarray_t *array, char *word);      //delete a string

#endif
