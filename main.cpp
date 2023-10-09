#include <cstdio>
#include <cstdlib>
#include <cstring>

struct paciente {
    char nome[50];
    int estado;
    struct paciente* prox;
};

typedef struct paciente Paciente;

typedef struct paciente Fila;

Fila* IniciaFila(){
    return nullptr;
}

int Vazia(Fila *fila){
    return(fila == nullptr);
}

Fila* Enfila(Fila* fila, char* nome, int estado){

    Paciente* aux;
    auto* novo = (Paciente *) malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    novo->estado = estado;
    novo->prox = nullptr;

    if (Vazia(fila) || estado > fila->estado) {
        novo->prox = fila;
        fila = novo;
    } else {
        aux = fila;
        while (aux->prox != nullptr && estado <= aux->prox->estado) {
            aux = aux->prox;
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
        return (Fila *) nullptr;
    }

    q = fila;
    fila = fila->prox;
    printf("# Prioridade %d: %s \n", q->estado, q->nome);

    free(q);

    return fila;
}

void imprimir_inicio_ao_fim(Fila *fila) {
    Paciente *pac;
    if (Vazia(fila)) {
        printf("\nFila Vazia!!");
    } else {
        printf("Fila de espera completa e em ordem de prioridade: \n");
        pac = fila;
        while (pac != nullptr) {
            printf("# %d - %s\n", pac->estado, pac->nome);
            pac = pac->prox;
        }
    }
}

int main(){

    Fila* fila = IniciaFila();
    int estado;
    char nome[25];
    int i, max=6;

    for (i = 0 ; i <= max ; i++) {
        printf("Nome do paciente: ");
        scanf("%s", &nome);

        do {
            printf("\n Selecione o estado do paciente: \n1 - pouco urgente \n2 - urgente \n3 - muito urgente \n\n");
            scanf("%d", &estado);
        } while ((estado != 1) && (estado != 2) && (estado != 3));

        fila = Enfila(fila, nome, estado);
        imprimir_inicio_ao_fim(fila);
    }

    printf("\nFIM DA ENTRADA (atendendo por ordem de prioridade)\n\n");

    do {
        fila = Desenfila(fila);
    } while (!Vazia(fila));

}