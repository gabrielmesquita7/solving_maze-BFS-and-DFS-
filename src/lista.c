#include "lista.h"
#include "matriz.h"

void Swap(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void LInsert(Lista *l, Item d){
	if (l->last >= MAXLIST){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void LRemove(Lista *l, Item d){
	bool ok = false;

	if(l->first == l->last)
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vet[i].l == d.l && l->vet[i].c == d.c){
				Swap(&l->vet[i], &l->vet[i+1]);
				ok = true;	
			}
	
		if(ok)
			l->last --;
	}
}

void LImprime(Lista *l){
	printf("\n");
	for(int i=l->first; i<l->last; i++)
		printf("(%d,%d)\t", l->vet[i].l, l->vet[i].c);
	printf("\n\n");
}

void LPercorre(Lista *l, Matriz *m){
	Item pos;
	pos.l = 0;
	pos.c = 0;
	LInsert(l, pos);
	int cont = l->first, cont2 = l->first+1;
	m->vis[pos.l][pos.c] = cont;
	while((l->vet[cont].l != m->rows-1 || l->vet[cont].c != m->cols-1) || cont == l->last){
		if((l->vet[cont].l)+1 < m->rows && m->data[(l->vet[cont].l)+1][l->vet[cont].c] != -1 && m->vis[l->vet[cont].l+1][l->vet[cont].c] == -1){
			pos.l = l->vet[cont].l+1;
			pos.c = l->vet[cont].c;
			LInsert(l, pos);
			m->vis[pos.l][pos.c] = cont2;
			cont2++;
		}
		if(l->vet[cont].c+1 < m->cols && m->data[l->vet[cont].l][l->vet[cont].c+1] != -1 && m->vis[l->vet[cont].l][l->vet[cont].c+1] == -1){
			pos.l = l->vet[cont].l;
			pos.c = l->vet[cont].c+1;
			LInsert(l, pos);
			m->vis[pos.l][pos.c] = cont2;
			cont2++;
		}
		cont++;
	}
	if(l->vet[cont].l == m->rows-1 && l->vet[cont].c == m->cols-1){
		printf("Número de interações: %d\n", cont);
		LImprime(l);
		print_matriz(m);
	}else{
		printf("Obstáculo no caminho, impossível chegar ao fim.");
	}
}


