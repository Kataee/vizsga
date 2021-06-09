#include "hashtable.h"
#include "../common/commondefines.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

hashtable_t *hashtable_create(int capacity) {
    //allocating memory
    hashtable_t *newHashTable = (hashtable_t *) malloc(sizeof(hashtable_t));

    if (newHashTable == NULL) {    //check if memory was allocated successfully
        return NULL;
    }

    newHashTable->capacity = capacity;
    newHashTable->elements = 0;

    //allocating memory
    newHashTable->table = (char **) malloc(capacity * sizeof(char*));
    if (!newHashTable->table) {   //check if memory was allocated successfully
        free(newHashTable);
        return NULL;
    }

    for (int i = 0; i < capacity; ++i) {
        newHashTable->table[i] = (char *) calloc(MAX_WORD_LENGTH, sizeof(char));   //allocating memory

        if (newHashTable->table[i] == NULL) {   //check if memory was allocated successfully
            free(newHashTable->table);
            free(newHashTable);
            return NULL;
        }
    }

    return newHashTable;
}

int sLength(char *s) {
    int element = 0;

    for (int i = 0; i < strlen(s); ++i) {
        element += s[i];
    }

    return element;
}


void hashtable_add(hashtable_t *array, char *s) {
    array->elements++; //increasing element count

    int element = sLength(s);
    int i = 0, j;

    do {
        j = (element + i) % array->capacity;
        if (strlen(array->table[j]) == 0) {
            strcpy(array->table[j], s);
            return;
        } else {
            i++;
        }
    } while (i != array->capacity);
}

void hashtable_print(hashtable_t *array) {
    printf("Hash table: ");

    for (int i = 0; i < array->capacity; ++i) {
        if (strlen(array->table[i]) > 0) {
            printf("%s ", array->table[i]);
        }
    }
}

void hashtable_delete(hashtable_t *hash, char* s) {
    int i = 0, j;
    int element = sLength(s);

    do {
        j = (element + i) % hash->capacity;
        if (strcmp(hash->table[j], s) == 0) {
            strcpy(hash->table[j], "\0");
            break;
        } else {
            i++;
        }

    } while (strlen(hash->table[j]) > 0 && (i != hash->capacity));

}

char *hashtable_search (hashtable_t *hash, char* s) {
    int i = 0, j = 0;
    int element = sLength(s);

    do {
        j = (element + i) % hash->capacity;
        if (strcmp(hash->table[j], s) == 0) {
            printf("found: %s\n", hash->table[j]);
            return hash->table[j];
        }
        i++;
    } while (strlen(hash->table[j]) > 0 && (1 != hash->capacity));

    return NULL; //ha nincs meg a keresett elem
}
