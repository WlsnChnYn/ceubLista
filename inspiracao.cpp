#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
};

typedef struct No No;

typedef struct{
    No *inicio;
    No *fim;
    int tamanho;
}
        Fila;

void IniciaFila(Fila *fila){
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->tamanho = 0;
}

int Vazia(Fila *fila){
    return(fila->fim == NULL);
}

void Enfila(int x, Fila *fila){

    No *aux;

    aux = (No *) malloc(sizeof(No));   // malloc aloca espaco de memoria
    aux->valor = x;
    aux->prox = NULL;

    if (fila->fim == NULL){
        fila->inicio = aux;
    }
    else{
        fila->fim->prox = aux;
    }

    fila->fim = aux;
    fila->tamanho++;
}

int Desenfila(Fila *fila){
    No *q;
    int v;

    if(Vazia(fila)){
        printf("Fila vazia \n\n");
        return 0;
    }

    q = fila->inicio;
    v = q->valor;
    fila->inicio = q->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(q);
    fila->tamanho--;
    return v;
}

int main(){
    int i, numero, max=5;
    Fila fila;
    IniciaFila(&fila);

    for (i=0; i<max; i++){
        printf("Leitura do valor %d: ",i);
        scanf("%d",&numero);
        Enfila(numero, &fila);
        printf("Enfilerou: %d \n\n", numero);
    }

    for(i=0; i<max; i++){
        numero = Desenfila (&fila);
        printf ("Desenfilerou: %d \n", numero);
    }
}