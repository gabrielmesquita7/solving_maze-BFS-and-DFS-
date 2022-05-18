#include "lista.h"
#include "pilha.h"


int main(){
	FILE *myfile = fopen ("gameconfig.txt", "r");
	SearchType *st = malloc(sizeof(char)*20);
	Matriz *m = TokenizerM(myfile, st);
	printf("Matriz Inicial: \n");
	print_matriz(m);
	TipoCaminho(m, st);

	return 0;
}
