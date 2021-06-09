#include "wordarray.h"

#include "../common/commondefines.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

wordarray_t *wordarray_create(int size) {
    //allocating memory
    wordarray_t *newArray = (wordarray_t *) malloc(sizeof(wordarray_t));

    if (newArray == NULL) {    //check if memory was allocated successfully
        return NULL;
    }

    //setting size, maximum number of strings
    newArray->size = size;
    newArray->rear = 0;

    //allocating memory
    newArray->words = (char **) malloc(size * sizeof(char *));
    if (newArray->words == NULL) {   //check if memory was allocated successfully
        free(newArray);
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        newArray->words[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));   //allocating memory
        if (newArray->words[i] == NULL) {   //check if memory was allocated successfully
            free(newArray->words);
            free(newArray);
            return NULL;
        }
    }

    return newArray;
}

void wordarray_load(const char* fileName, wordarray_t *array) {
    FILE *f; //file stream

    // check if file can be opened
    if ((f = fopen(fileName, "r")) == NULL) {
        printf("Error opening file"); exit(4);
    }
    printf("size %i\n", array->size);
    //read
    for (int i=0; i < array->size; ++i) {
        if (feof(f)) {  //if end of file == true
            printf("End of file\n");
            //realloc(array->words,i); //breaks the stuff
            //inkább free() a megmaradt felhasználatlan chr[x] részeket
            array->size = i; //adjusting size
            printf("Reallocated, size %i\n", array->size);
            fclose(f);  //closeing file
            return;
        }
        fscanf(f, "%s", array->words[i]); //read a string from file and put into array
    }
}

//print the strings to the console
void wordarray_print(wordarray_t *array) {
    for (int i = 0; i < array->rear; ++i) {
        printf("%d: %s ", i, array->words[i]);
    }

    printf("\n");
}


//itt valami nem jó, ha sok elemet adunk hozzá akkor a legelső és néha a második
// string elvész, random karakterek íródnak ki helyette
//talán a memóriakezelés
bool wordarray_add(wordarray_t* array, char* s) {
    if (array->rear == array->size - 1) {
        array->size *= 2;
        array->words = (char **) realloc(array->words, array->size * sizeof(char *));

        if (array->words == NULL) {
            return false;
        }

        for (int i = array->rear + 1; i < array->size; i++) {
            array->words[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));

            if (array->words[i] == NULL) {
                return false;
            }
        }
    }

    strcpy(array->words[array->rear], s);
    array->rear++;
    return true;
}

int wordarray_search(wordarray_t *array, char *s) {
    for (int i = 0; i < array->size; ++i) {
        if (strcmp(s, array->words[i]) == 0) { //compare strings
            return i; //return location of string
        }
    }

    return -1; //return NULL if not found
}


//return array->size
int wordarray_count(wordarray_t *array) {
    return array->size;
}

bool wordarray_delete(wordarray_t *array, char *s) {
    int target_idx = wordarray_search(array, s);

    if (target_idx == -1) {
        return false;
    }

    for (int i = target_idx; i < array->size; ++i) {
        strcpy(array->words[i], array->words[i + 1]);
    }

    array->size--;
    return true;
}
