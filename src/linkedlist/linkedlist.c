#include "linkedlist.h"

#include "../app/counters.h"
#include "../common/commondefines.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool list_insert(linkedlist_t **head, char *word) {
    c_cm_add(2);

    linkedlist_t *new_node = (linkedlist_t *) malloc(sizeof(linkedlist_t));
    if (new_node == NULL) {
        return false;
    }

    new_node->next = *head;
    new_node->word = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));

    if (new_node->word == NULL) {
        free(new_node);
        return false;
    }

    strcpy(new_node->word, word);
    *head = new_node;
    return true;
}

bool list_remove(linkedlist_t **head, char *word) {
    linkedlist_t *temp = *head;

    c_cm_inc();

    if (temp != NULL && strcmp(temp->word, word) == 0) {
        *head = temp->next;
        free(temp);
        return true;
    }

    linkedlist_t *prev;

    while (temp != NULL) {
        c_cm_inc();

        if (strcmp(temp->word, word) == 0) {
            prev->next = temp->next;
            free(temp);
            return true;
        }

        prev = temp;
        temp = temp->next;
    }

    return false;
}

linkedlist_t *list_search(linkedlist_t *head, char *word) {
    while (head != NULL) {
        c_cm_inc();

        if (strcmp(head->word, word) == 0) {
            return head;
        }
    }

    return NULL;
}

int list_count(linkedlist_t *head) {
    c_cm_inc();
    c_op_inc();

    if (head == NULL) {
        return 0;
    }

    return 1 + list_count(head->next);
}

void list_print(linkedlist_t *head) {
    c_cm_inc();

    if (head == NULL) {
        return;
    }

    list_print(head->next);
    printf("%s ", head->word);
}

void list_free(linkedlist_t *head) {
    linkedlist_t *temp = head, *next;

    while (temp != NULL) {
        c_cm_inc();

        next = temp->next;
        free(temp->word);
        free(temp);
        temp = next;
    }
}
