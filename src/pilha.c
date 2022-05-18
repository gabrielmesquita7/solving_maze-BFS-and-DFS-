#include "pilha.h"


void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha *p, Pitem d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Pitem *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
		*d = p->vet[p->top];
	}
}

void DFS(Pilha *p, Matriz *m){
	Pitem aux;
	aux.l = 0;
	aux.c = 0;
	int i=p->base, j=p->base;
    int count2=p->base+1;
	PUSH(p, aux);
	m->vis[aux.l][aux.c] = count2;
	while((p->vet[i].l != m->rows-1 || p->vet[j].c != m->cols-1) && i < p->top){
		if (j == 0){
			if(i < m->rows-1 && m->data[(p->vet[i].l)+1][p->vet[j].c] != -1 && m->vis[p->vet[i].l+1][p->vet[j].c] == -1){
				i++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}
			else if(m->data[p->vet[i].l][(p->vet[j].c)+1] != -1 && m->vis[p->vet[i].l][p->vet[j].c+1] == -1){
				j++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}
			else if(m->data[(p->vet[i].l)-1][p->vet[j].c] != -1 && m->vis[p->vet[i].l-1][p->vet[j].c] == -1){
				i--;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}else{
				aux.l = i;	
				aux.c = j;
				POP(p, &aux);
				i--;
			}	
		}else if(i != m->rows-1 && j == m->cols-1){
			if(i < m->rows-1 && m->data[(p->vet[i].l)+1][p->vet[j].c] != -1 && m->vis[p->vet[i].l+1][p->vet[j].c] == -1){
				i++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}else if(i < m->rows-1 && m->data[p->vet[i].l][p->vet[j].c-1] != -1 && m->vis[p->vet[i].l][p->vet[j].c-1] == -1){
				j--;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}else{
				aux.l = i;	
				aux.c = j;
				POP(p, &aux);
			}
		}else{
			if(i < m->rows-1 && m->data[(p->vet[i].l)+1][p->vet[j].c] != -1 && m->vis[p->vet[i].l+1][p->vet[j].c] == -1){
				i++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;			
			}else if(m->data[p->vet[i].l][(p->vet[j].c)+1] != -1 && m->vis[p->vet[i].l][p->vet[j].c+1] == -1){
				j++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}else if(m->data[p->vet[i].l][p->vet[j].c-1] != -1 && m->vis[p->vet[i].l][p->vet[j].c-1] == -1){
				j--;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}else if(m->data[(p->vet[i].l)-1][p->vet[j].c] != -1 && m->vis[p->vet[i].l-1][p->vet[j].c] == -1){
				i--;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				m->vis[aux.l][aux.c] = count2;
				count2++;
			}else{
				aux.l = i;	
				aux.c = j;
				POP(p, &aux);
				i--;
			}
		}
	}
	if(p->vet[i].l == m->rows-1 && p->vet[j].c == m->cols-1){
		printf("BFS: \n");
		print_matriz(m);
		printf("Numero de interacoes: %d\n", count2);
	}else{
		printf("Obstaculo no caminho, impossivel chegar ao fim.");
	}
}







