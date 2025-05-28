#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Celula{
	int elemento;
	struct Celula *prox;
}Celula;

typedef struct Pilha{
	Celula *topo;
}Pilha;

Celula* new_celula(int x){
	Celula *tmp = (Celula *)malloc(sizeof(Celula));
	tmp->elemento = x;
	tmp->prox = NULL;
	return tmp;
}

Pilha* new_pilha(){ 
	Pilha *tmp = (Pilha *)malloc(sizeof(Pilha)); 
	tmp->topo = NULL;
	return tmp;
}

void push(Pilha *pilha,int x){
	if(pilha->topo != NULL){
		Celula *tmp = new_celula(x);
		tmp->prox = pilha->topo;
		pilha->topo = tmp;
	}else{
		pilha->topo = new_celula(x);
	}
}

void pop(Pilha *pilha){
	if(pilha->topo != NULL){
		Celula *tmp = pilha->topo;
		pilha->topo = pilha->topo->prox;
		free(tmp);
	}else{
		printf("EMPTY\n");
	}
}

void min(Pilha *pilha){
	int min = pilha->topo->elemento;
	for(Celula *i = pilha->topo->prox; i != NULL; i = i->prox){
		if(i->elemento < min){
			min = i->elemento;
		}
	}
	printf("%d\n",min);
}

int main(){
	Pilha *pilha = new_pilha();
	int op;

	scanf("%d",&op);
	getchar();

	for(int i = 0; i < op; i++){
		char line[255];

		scanf("%s",line);

		if(strcmp(line,"PUSH") == 0){
			int x;
			scanf("%d",&x);
			getchar();
			push(pilha,x);
		}
		if(strcmp(line,"MIN") == 0){
			min(pilha);
		}
		if(strcmp(line,"POP") == 0){
			pop(pilha);
		}
	}

	return 0;
}