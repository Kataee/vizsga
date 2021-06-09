//
// Created by Kataee on 09/06/2021.
//

#ifndef VIZSGA_DOUBLYLINKEDLIST_H
#define VIZSGA_DOUBLYLINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);
void printList(struct Node* node);
void deleteNode(struct Node** head_ref, struct Node* del);



#endif //VIZSGA_DOUBLYLINKEDLIST_H
