#ifndef PILHA_H 
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 10

typedef struct Pitem{
	int val;
}Pitem;

typedef struct Pilha{
	Pitem vet[MAXTAM];
	int top;
	int base;
}Pilha;

void FPVazia(Pilha *p);
void PUSH(Pilha *p, Pitem d);
void POP(Pilha *p, Pitem *d);
void PRemove(Pilha *p, Pitem d);
void PImprime(Pilha *p);

#endif