#include "bintree.h"

#include "../app/counters.h"
#include "../common/commondefines.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bintree_t *bintree_create(char *word) {
    c_cm_add(2); // two comparisons

    bintree_t *node = (bintree_t *) malloc(sizeof(bintree_t));
    if (node == NULL) { // cm 1
        return NULL;
    }

    node->word = malloc(MAX_WORD_LENGTH * sizeof(char));
    node->left = NULL;
    node->right = NULL;

    if (node->word == NULL) { // cm 2
        free(node);
        return NULL;
    }

    strcpy(node->word, word);

    return node;
}

bintree_t *bintree_insert(bintree_t *head, char *word) {
    c_cm_add(2); // two comparisons on each recursive call

    if (head == NULL) { // cm 1
        return bintree_create(word);
    }

    if (strcmp(word, head->word) < 0) { // cm 2
        head->left = bintree_insert(head->left, word);
    } else {
        head->right = bintree_insert(head->right, word);
    }

    return head;
}

bintree_t *bintree_search(bintree_t *head, char *word) {
    c_cm_inc();

    if (head == NULL) { // cm 1
        return NULL;
    }

    c_cm_inc();
    if (strcmp(head->word, word) == 0) { // cm 2
        return head;
    }

    c_cm_inc();
    return strcmp(head->word, word) < 0 // cm 3
        ? bintree_search(head->right, word)
        : bintree_search(head->left, word);
}

bintree_t *bintree_minvalue(bintree_t *head) {
    bintree_t *aux = head;

    while (aux && aux->left != NULL) {
        c_cm_inc(); // one comparison in each iteration of the loop
        aux = aux->left;
    }

    return aux;
}

bintree_t *bintree_remove(bintree_t *head, char *word) {
    c_cm_inc();

    if (head == NULL) {
        return NULL;
    }

    c_cm_add(4);
    if (strcmp(head->word, word) < 0) {
        head->right = bintree_remove(head->right, word);
    } else if (strcmp(head->word, word) > 0) {
        head->left = bintree_remove(head->left, word);
    } else {
        if (head->left == NULL) {
            bintree_t *temp = head->right;
            free(head);
            return temp;
        } else if (head->right == NULL) {
            c_cm_inc();
            bintree_t *temp = head->left;
            free(head);
            return temp;
        }

        bintree_t *temp = bintree_minvalue(head->right);
        head->word = temp->word;
        head->right = bintree_remove(head->right, temp->word);
    }

    return head;
}

void bintree_free(bintree_t *head) {
    c_cm_inc();

    if (head == NULL) {
        return;
    }

    bintree_free(head->left);
    bintree_free(head->right);

    free(head->word);
    free(head);
}

int bintree_count(bintree_t *head) {
    c_cm_inc();
    c_op_add(2);

    if (head == NULL) {
        return 0;
    }

    return 1 + bintree_count(head->left) + bintree_count(head->right);
}

void bintree_print(bintree_t *head) {
    c_cm_inc();

    if (head == NULL) {
        return;
    }

    bintree_print(head->left);
    printf("%s ", head->word);
    bintree_print(head->right);

}

