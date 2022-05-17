#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "matriz.h"

#define MAXLIST 50

typedef struct Item{
	int l;
	int c;
}Item;

typedef struct Lista{
	Item vet[MAXLIST];
	int first;
	int last;
}Lista;

void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LRemove(Lista *l, Item d);
void Swap(Item *a, Item *b);
void LImprime(Lista *l);
void LPercorre(Lista *l, Matriz *m);

#endif