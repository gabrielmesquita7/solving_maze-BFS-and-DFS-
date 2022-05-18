#include "lista.h"
#include "pilha.h"
#include "matriz.h"

Matriz* criar_matriz(int rows, int cols){
    struct Matriz* matriz = malloc(sizeof(Matriz));
    matriz->rows = rows;
    matriz->cols = cols;
    int** data = malloc(sizeof(int*) * rows);
    int** vis = malloc(sizeof(int*) * rows); 
    for(int i = 0; i < rows; i++){
        data[i] = calloc(cols, sizeof(int));
        vis[i] = calloc(cols, sizeof(int));
    }
    matriz->data = data;
    matriz->vis = vis;
    return matriz;
}

Matriz* preenche_matriz(int rows, int cols) {
    struct Matriz *matriz = criar_matriz(rows, cols);
    for(int x = 0; x < rows; x++) {
        for(int y = 0; y < cols; y++) {
            matriz->data[x][y] = 0;
            matriz->vis[x][y] = -1;
        }
    }
    return matriz;    
}

void print_matriz(Matriz* m){
    for(int x = 0; x < m->rows; x++) {
        for(int y = 0; y < m->cols; y++) {
            if(m->vis[x][y] == -1){
                if(m->data[x][y]==0){
                    printf("O\t");
                }else{
                    printf("X\t");
                }
            }else{
                printf("%d\t", m->vis[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

Matriz* TokenizerM(FILE *ptr, SearchType *st){
    char buff[MAXC] = "";
	char *token = NULL;
	const char *delim = " x[,]";
    int y = 0, cols = 0, rows = 0, counter = 0, x = 0;
    int auxl[60];
    int auxc[60];
    for(int i=0;i<60;i++){ auxl[i] = 0; auxc[i] = 0;}
    int l = 0, c = 0;

  

    if (!ptr){
		perror ("abertura do arquivo falhou\n");
	}

	while(fgets(buff, MAXC, ptr) != NULL){
		size_t len = strlen(buff);
		if (len == MAXC - 1 && buff[len-1] != '\n'){
			fputs ("error: linha muito longa.\n", stderr);
		}
        if (counter == 0){
            for (token = strtok(buff, delim); token; token = strtok(NULL, delim)){
                if(y == 0){
                    rows = atoi(token);
                }
                if(y == 1){
                    cols = atoi(token);
                }
            y++;
            }
        }
        if(counter == 1){
            for (token = strtok(buff, delim); token; token = strtok(NULL, delim)){ 
                if(x % 2 == 0 || x==0){
                    auxl[l] = atoi(token);
                    l++;
                }else{
                    auxc[c] = atoi(token);
                    c++; 
                }
                x++;
		    }
        }
        if(counter == 2){
            for (token = strtok(buff, delim); token; token = strtok(NULL, delim)){
                strcpy(st->searchtype, token);
		    }
        }
        counter++;
    }
	fclose (ptr);
    Matriz* m1 = preenche_matriz(rows, cols);
    //preencher obstaculos
    counter = 0;
    c = 0;
    l = 0;
    for(int i = 0; i<x/2;i++){
        m1->data[auxl[l]][auxc[c]] = -1;
        l++;
        c++;
    }
    //
    printf("\n\n");
    return m1;
}

void TipoCaminho(Matriz *m, SearchType *st){
    if(strcmp(st->searchtype, "BFS") == 0){
        Lista *l = malloc(sizeof(Lista));
        FLVazia(l);
        BFS(l, m);
    }else{
        if(strcmp(st->searchtype, "DFS") == 0){
            Pilha *p = malloc(sizeof(Pilha));
            FPVazia(p);
            DFS(p, m);
        }else{
            printf("Método inválido!");
        }
    }
}