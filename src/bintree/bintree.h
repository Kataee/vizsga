#ifndef __BINTREE_H
#define __BINTREE_H

#include <stdbool.h>

typedef struct bintree {
  char *word;
  struct bintree *left, *right;
} bintree_t;

bintree_t *bintree_create(char *word);
bintree_t *bintree_insert(bintree_t *head, char *word);
bintree_t *bintree_search(bintree_t *head, char *word);
bintree_t *bintree_remove(bintree_t *head, char *word);
int bintree_count(bintree_t *head);
void bintree_print(bintree_t *head);
void bintree_free(bintree_t *head);

#endif
