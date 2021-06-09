#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <stdbool.h>

typedef struct linkedlist {
    char *word;
    struct linkedlist *next;
} linkedlist_t;

bool list_insert(linkedlist_t **head, char *word);
bool list_remove(linkedlist_t **head, char *word);
linkedlist_t *list_search(linkedlist_t *head, char *word);
int list_count(linkedlist_t *head);
void list_print(linkedlist_t *head);
void list_free(linkedlist_t *head);

#endif
