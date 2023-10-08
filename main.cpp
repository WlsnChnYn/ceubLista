#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente {
    char nome[50];
    int estado;
    paciente* prox;
};

typedef struct paciente Paciente;

typedef struct paciente Fila;

Fila* IniciaFila(void){
    return NULL;
}

int Vazia(Fila *fila){
    return(fila == NULL);
}

Fila* Enfila(Fila* fila, char* nome, int estado){

    Paciente* aux;
    Paciente* novo = (Paciente *) malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    novo->estado = estado;
    novo->prox = NULL;

    if (fila == NULL) {
        printf("aqui null");

        fila = novo;
    } else {
        aux = fila;
        while (aux->prox != NULL && novo->estado <= aux->prox->estado) {
        printf("aqui not null");
            aux = aux->prox;
        printf("aqui not null fim");
        }
        novo->prox = aux->prox;
        aux->prox = novo;

    }

    return fila;
}

Fila * Desenfila(Fila *fila) {
    Paciente* q;

    if(Vazia(fila)){
        printf("Fila vazia \n\n");
        return (Fila *) NULL;
    }

    q = fila;
    fila = fila->prox;
    printf("# Prioridade %d: %s \n", q->estado, q->nome);

    free(q);

    return fila;
}

int main(){
    Fila* fila = IniciaFila();

    fila = Enfila(fila, "fulano", 3);
    fila = Enfila(fila, "fulanoooooo", 1);
    fila = Enfila(fila, "fulanaaaaa", 2);
    fila = Enfila(fila, "fulaneeeee", 3);
    fila = Enfila(fila, "fulan@", 2);
    fila = Enfila(fila, "fulanoooooofasdfasdrfewav", 2);

    printf("\nFIM DA ENTRADA (atendendo por ordem de prioridade)\n\n");

    do {
        fila = Desenfila(fila);
    } while (!Vazia(fila));

}