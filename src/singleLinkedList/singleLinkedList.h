//
// Created by Kataee on 09/06/2021.
//

#ifndef VIZSGA_SINGLELINKEDLIST_H
#define VIZSGA_SINGLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct NodeType{
    int info;
    struct NodeType *next;
}NodeType;

extern NodeType *front, *p;

void inicializalas();
NodeType Create(NodeType **);
void ListaBejaras();
void ElemBeszurasElore(int num);
void ElemBeszurasVegere(int num);
void BeszurasMegadottHelyre(int num, int poz);
void TorlesElsoElem();
void TorlesUtolsoElem();
void ListabolTorles(int torlendo);
void ListaTeljesTorlese();
bool ListabanKereses(int n);

void ElemBeszurasSorrendben(int num);
void swapListItem(int* a, int* b);
#endif //VIZSGA_SINGLELINKEDLIST_H
