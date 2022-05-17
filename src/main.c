#include "lista.h"
#include "pilha.h"
#include "matriz.h"

int main(){
	FILE *myfile = fopen ("gameconfig.txt", "r");
	SearchType *st = malloc(sizeof(char)*20);
	Matriz *m = TokenizerM(myfile, st);
	print_matriz(m);
	TipoCaminho(m, st);

/*	Lista l;
	Item aux;
	Pilha p;
	Pitem paux;
	//---------lista-------------
	FLVazia(&l);

	aux.val = 10;
	LInsert(&l, aux);
	aux.val = 20;
	LInsert(&l, aux);
	aux.val = 30;
	LInsert(&l, aux);

	LImprime(&l);

	aux.val = 20;
	LRemove(&l, aux);

	LImprime(&l);
	//---------pilha--------------
	FPVazia(&p);
	
	paux.val = 10;
	PUSH(&p, paux);
	paux.val = 20;
	PUSH(&p, paux);
	paux.val = 30;
	PUSH(&p, paux);

	PImprime(&p);

	paux.val = 20;
	PRemove(&p, paux);
	paux.val = 30;
	PRemove(&p, paux);
	
	PImprime(&p);
*/
	return 0;
}
