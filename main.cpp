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

Fila* Enfila(Fila* fila, Paciente* novo){
    if (Vazia(fila) || novo->estado > fila->estado) {
        novo->prox = fila;
        return novo;
    }
    fila->prox = Enfila(fila->prox, novo);
    return fila;
}

Paciente *novoPaciente(const char *nome, int estado) {
    auto* novo = (Paciente *) malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    novo->estado = estado;
    novo->prox = nullptr;
    return novo;
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
    Paciente* paciente;
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

        paciente = novoPaciente(nome, estado);
        fila = Enfila(fila, paciente);
        imprimir_inicio_ao_fim(fila);
    }

    printf("\nFIM DA ENTRADA (atendendo por ordem de prioridade)\n\n");

    do {
        fila = Desenfila(fila);
    } while (!Vazia(fila));

}