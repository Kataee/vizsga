//
// Created by Kataee on 09/06/2021.
//

#include "singleLinkedList.h"
NodeType *front, *p;

void inicializalas(){
    Create(&front);
    Create(&p);
}

NodeType Create(NodeType** node){
    (*node) = (NodeType*) malloc (1*sizeof(NodeType));
    (*node)->next = NULL;
}

void ListaBejaras(){
    if(front->next == NULL){
        printf("A sor ures!\n");
        return;
    }
    p = front;
    while(p->next != NULL){
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

void ElemBeszurasElore(int num){
    NodeType *new;
    Create(&new);
    new->info = num;
    new->next = front;
    front = new;
}

void ElemBeszurasVegere(int num){
    NodeType * new;
    Create(&new);
    new->info = num;
    new->next = NULL;
    if(front == NULL){
        front = new;
    }
    else{
        p = front;
        while(p->next != NULL){
            p = p->next;
        }
        p->info = num;
        p->next = new;
    }
}

void ElemBeszurasSorrendben(int num) {
    NodeType *new;
    Create(&new);
    new->info = num;
    new->next = NULL;
    if (front == NULL) {
        front = new;
        return;
    }

    NodeType *temp;
    Create(&temp);
    temp = front;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;


    temp=front;
    while (new->info < temp->info) {
        swapListItem(&new->info, &temp->info);
        if (temp->next == NULL) {
            return;
        }
        temp = temp->next;
    }


}

void swapListItem(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BeszurasMegadottHelyre(int num, int poz){
    NodeType * new;
    Create(&new);
    new->info = num;
    if((front == NULL) || (poz == 1)){
        new->next = front;
        front = new;
    }
    else{
        p = front;
        for(int i = 2; (i < poz) && (p->next != NULL); i++){
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
}

void TorlesElsoElem(){
    if(front->next != NULL){
        p = front;
        front = front->next;
        free(p);
    }
    else{
        printf("A sor ures!\n");
    }
    return;
}

void TorlesUtolsoElem(){
    if(front->next != NULL){
        p = front;
        while(p->next->next != NULL){
            p = p->next;
        }
        p->next = NULL;
        p = p->next;
        free(p);
    }
}

void ListabolTorles(int torlendo){
    NodeType * e = NULL;
    p = front;
    while((p->next != NULL) && (p->info != torlendo)){
        e = p;
        p = p->next;
    }
    if(p->next != NULL){
        if(e == NULL){
            front = p->next;
        }
        else{
            e->next = p->next;
            free(p);
        }
    }
    else{
        printf("Nince ilyen elem\n");
    }
}

void ListaTeljesTorlese(){
    while(front->next != NULL){
        p = front;
        front = front->next;
        free(p);
    }
}

bool ListabanKereses(int n){
    p = front;
    while((p->next != NULL) && (p->info != n)){
        p = p->next;
    }
    if(p->next != NULL){
        return true;
    }
    else{
        return false;
    }
}
